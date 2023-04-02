import requests

# Ask the user for the name of the Pokemon
name = input("Enter the name of a Pokemon: ")

# Fetch the Pokemon data from the PokeAPI
url = f"https://pokeapi.co/api/v2/pokemon/{name.lower()}"
response = requests.get(url)
if response.status_code != 200:
    print("Pokemon not found")
    exit()

data = response.json()

print(f"Name: {data['name'].capitalize()}")
print("Abilities: ")
for ability in data["abilities"]:
    print(f"- {ability['ability']['name'].capitalize()}")

