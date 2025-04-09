import os
import re
import json
import sys

exclude_list = [
    'CookZ_BoxedDishes',
    'CookZ_CannedDishes',
    'CookZ_Sausage'
]

def find_all_config_files(root_dir):
    config_files = []
    for dirpath, _, filenames in os.walk(root_dir):
        for file in filenames:
            if file.lower() == 'config.cpp':
                config_files.append(os.path.join(dirpath, file))
    return config_files

def find_cookz_classes(file_paths, exclude_contains=None):
    if exclude_contains is None:
        exclude_contains = []

    found_classes = []
    for file_path in file_paths:
        with open(file_path, 'r', encoding='utf-8') as f:
            for line_number, line in enumerate(f, start=1):
                match = pattern.search(line)
                if match:
                    class_name = match.group(1)
                    if class_name.endswith('Base'):
                        continue
                    if any(skip in class_name for skip in exclude_contains):
                        continue
                    found_classes.append(class_name)
    return found_classes

def write_types_xml(class_names, output_path):
    with open(output_path, 'w', encoding='utf-8') as f:
        f.write('<?xml version="1.0" encoding="UTF-8" standalone="yes"?>\n')
        f.write('<types>\n')
        for class_name in class_names:
            f.write(f'    <type name="{class_name}">\n')
            f.write('        <nominal>0</nominal>\n')
            f.write('        <lifetime>9000</lifetime>\n')
            f.write('        <restock>0</restock>\n')
            f.write('        <min>0</min>\n')
            f.write('        <quantmin>-1</quantmin>\n')
            f.write('        <quantmax>-1</quantmax>\n')
            f.write('        <cost>100</cost>\n')
            f.write('        <flags count_in_cargo="0" count_in_hoarder="0" count_in_map="1" count_in_player="0" crafted="1" deloot="0" />\n')
            f.write('        <category name="food" />\n')
            f.write('    </type>\n')
        f.write('</types>\n')

def write_items_txt(class_names, output_path):
    with open(output_path, 'w', encoding='utf-8') as f:
        for class_name in class_names:
            f.write(f'{class_name}\n')

def write_expansion_trader_example(class_names, output_file):
    data = {
        "m_Version": 12,
        "DisplayName": "Cooking",
        "Icon": "Frying Pan",
        "Color": "2f9900",
        "IsExchange": 0,
        "InitStockPercent": 75.0,
        "Items": []
    }
    for class_name in class_names:
        if class_name.endswith("_Opened"):
            continue
        item_entry = {
            "ClassName": class_name,
            "MaxPriceThreshold": 20,
            "MinPriceThreshold": 10,
            "SellPricePercent": -1.0,
            "MaxStockThreshold": 100,
            "MinStockThreshold": 1,
            "QuantityPercent": -1,
            "SpawnAttachments": [],
            "Variants": []
        }
        data["Items"].append(item_entry)

    with open(output_file, "w") as f:
        json.dump(data, f, indent=4)

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: python script.py <mod_name>")
        sys.exit(1)

    mod_name = sys.argv[1]
    root_directory = f'P:\\{mod_name}'
    pattern = re.compile(rf'class\s+({re.escape(mod_name)}_\w+)\s*:')

    config_files = find_all_config_files(root_directory)
    print(f'Found {len(config_files)} config.cpp files in {root_directory}')

    results = find_cookz_classes(config_files, exclude_list)
    print(f'Found {len(results)} CookZ class definitions')

    output_base = os.path.join('P:\\ModsMetaData', f'@{mod_name}')
    os.makedirs(output_base, exist_ok=True)

    write_types_xml(results, os.path.join(output_base, f'{mod_name.lower()}_types.xml'))
    print('Wrote types XML')

    write_items_txt(results, os.path.join(output_base, f'{mod_name.lower()}_items.txt'))
    print('Wrote items TXT')

    write_expansion_trader_example(results, os.path.join(output_base, f'{mod_name.lower()}_expansion_trader_example.json'))
    print('Wrote expansion trader example JSON')
