import uuid

original_uuid = uuid.uuid4()
my_uuid = str(original_uuid).replace('-', '').upper()
uuid_bytes = list((reversed(['0x' + x + y for x, y in zip(my_uuid[0::2], my_uuid[1::2])])))
uuid_array_string = "{" + ", ".join(uuid_bytes[:8]) + ", \\\n\t\t\t\t  " + ", ".join(uuid_bytes[8:]) + "}"
print("// clang-format off")
print(f"// UUID: {original_uuid}")
print(f"#define CUSTOM_SERVICE_UUID_BASE {uuid_array_string}")
print("// clang-format on")