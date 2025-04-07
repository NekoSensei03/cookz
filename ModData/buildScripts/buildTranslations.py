import csv
import json
import sys
import os
import re

if len(sys.argv) < 3:
    print(f"Usage: python {os.path.basename(__file__)} <input.json> <output.csv>")
    sys.exit(1)

input = sys.argv[1]
output = sys.argv[2]

# Read JSON data from a file
with open(input, 'r', encoding='utf-8') as file:
    data = json.load(file)

# Define the header for the CSV
header = [
    "Language", "original", "english", "czech", "german", "russian", "polish", "italian", "spanish", 
    "french", "chinese", "japanese", "portuguese", "chinesesimp"
]

# List to hold all rows to be written later
rows = []

# Iterate over each key in the data dictionary
for key, translations in data.items():
    row = {"key": key}  # Store the key without "STR_" prefix
    
    # Add entry for original - use 'en' entry
    row["original"] = translations.get("en", "")
    
    # Iterate through the languages and check if translation is empty, if so, use 'en'
    for lang in ["en", "cs", "de", "ru", "pl", "it", "es", "fr", "zh", "ja", "pt", "zh-cn"]:
        if (key.endswith("Opened_DS")):
            # Use the English translation if the current language translation is empty
            row[lang] = translations.get(lang, translations.get("en", "")) or translations.get("en", "")
        else:
            # Check if the translation exists, otherwise raise an error
            if lang not in translations or not translations[lang]:
                raise ValueError(f"Missing translation for key {key} language: {lang}")
            row[lang] = translations[lang]
    
    # Append the row to the list
    rows.append(row)

# Regular expression pattern to find keys in the format @SomeKey
key_pattern = re.compile(r'@([a-zA-Z0-9_&]+)')

# Now, modify the rows by replacing substrings like "@SomeKey"
for row in rows:
    for lang in ["original", "en", "cs", "de", "ru", "pl", "it", "es", "fr", "zh", "ja", "pt", "zh-cn"]:
        # Get the current translation value
        value = row[lang]
        
        # Find all occurrences of the pattern "@SomeKey"
        matches = key_pattern.findall(value)
        
        # For each match, replace it with the corresponding value from the data structure
        for key_ref in matches:
            if key_ref in data:
                # Replace "@SomeKey" with the translation in the current language (or fallback to 'en')
                replacement = data[key_ref].get(lang, data[key_ref].get("en", ""))
                value = value.replace(f"@{key_ref}", replacement)  # Replace substring with the actual value
            else:
                # Raise an error if the key is not found
                raise ValueError(f"Key '{key_ref}' not found in the data structure for language '{lang}'")
        
        # Store the modified value back into the row
        row[lang] = value

# After modification, now write all rows to the CSV file at once
with open(output, mode='w', newline='', encoding='utf-8') as file:
    writer = csv.writer(file, quotechar='"', quoting=csv.QUOTE_ALL)
    
    writer.writerow(header)
    
    # Prepare the rows in the format suitable for CSV, adding the "STR_" prefix to the key
    # Skip rows where the key starts with "@"
    csv_rows = [
        [f"STR_{row['key']}", row["original"], row["en"], row["cs"], row["de"], row["ru"], row["pl"], row["it"],
         row["es"], row["fr"], row["zh"], row["ja"], row["pt"], row["zh-cn"]] for row in rows if not row["key"].startswith("&")
    ]
    writer.writerows(csv_rows)  # Write all rows at once

# Manually add a trailing comma to the file using file handling to avoid extra empty value
with open(output, 'r+', encoding='utf-8') as file:
    content = file.read()
    # Adding a comma to the end of each line
    lines = content.splitlines()
    with open(output, 'w', encoding='utf-8') as file:
        for line in lines:
            file.write(line + ",\n")
print(f'Updated {output} - {len(rows)} rows')
