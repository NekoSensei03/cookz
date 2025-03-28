import re
import json

file_paths = [
    'P:\\CookZ\\config.cpp',
    'P:\\CookZ\\Scripts\\4_World\\dishes\\boxed\\config.cpp',
    'P:\\CookZ\\Scripts\\4_World\\dishes\\canned\\config.cpp',
    'P:\\CookZ\\Scripts\\4_World\\dishes\\cheese\\config.cpp',
    'P:\\CookZ\\Scripts\\4_World\\dishes\\sausage\\config.cpp',
]

exclude_list = [
    'CookZ_BoxedDishes',
    'CookZ_CannedDishes',
    'CookZ_Sausage'
]

pattern = re.compile(r'class\s+(CookZ_\w+)\s*:')

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

def write_types_xml(class_names, output_path='cookz_types.xml'):
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

def write_items_txt(class_names, output_path='cookz_items.txt'):
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
    results = find_cookz_classes(file_paths)
    print(f'Found {len(results)} items')
    write_types_xml(results, 'P:\\ModsMetaData\\@CookZ\\cookz_types.xml')
    print('Wrote types xml')
    write_items_txt(results, 'P:\\ModsMetaData\\@CookZ\\cookz_items.txt')
    print('Wrote items txt')
    write_expansion_trader_example(results, 'P:\\ModsMetaData\\@CookZ\\cookz_expansion_trader_example.json')
    print('Wrote expansion trader example json')
