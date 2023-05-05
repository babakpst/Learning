
# babak poursartip
# may 5, 2023


class Country:
    def __init__(self, name, population):
        self.name = name
        self.population = population

    def __repr__(self):
        return f'Country({self.name}, {self.population})'


item = Country('Iran',80_000_000)
print(item)

myList = [
                Country('Taiwan', 24_000_000),
                Country('Portugal', 10_000_000),
                Country('Netherlands', 17_500_000),
                Country('Nigeria', 198_000_000),
                Country('Niger', 24_000_000),
                Country('Japan', 128_000_000)
]


print(  sorted(myList, key=lambda item:item.population)) # order ascending population
print(  sorted(myList, key=lambda item:item.population, reverse=True)) # order decending population
print(  sorted(myList, key=lambda item:-item.population)) # order descending population

print(  sorted(myList, key=lambda item:(-item.population, item.name))) # order descending population but ascending name
print(  sorted(myList, key=lambda item:(-item.population, item.name), reverse=True )) # order descending population but ascending name





#iso = [('Taiwan', 'iso24000000'), ('Portugal', 'iso10000000'), ('Netherlands', 'iso17500000'), ('Nigeria', 'iso198000000'), ('Niger', 'iso24000000'), ('Japan', 'iso128000000')]
