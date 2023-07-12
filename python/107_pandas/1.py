
# babak poursartip
# June 30, 20223


import pandas as pd

#df = pd.read_csv('data/BankMarketingData.csv')
#df = pd.read_csv('data/SummerOlympicmedallists1896to2008-IOCCOUNTRYCODES.csv')
df = pd.read_csv('data/olympics.csv',skiprows=4)


# info --------------------------------------------------------------
print(df.head(5))
#df.head(5) # not working if it is not in the jupyter

df.info() # returns general info about the dataframe

# value_counts ------------------------------------------------------
# it returns a series object counting all the unique values. The first value is the most recurring element. The second element is the second most recurring element.

print("\n number of each unique values in the City series using value counts:")
print(df.City.value_counts(normalize=False, sort=True, ascending=False, bins=None, dropna=True))

print("\n number of each unique values in the Gender series using value counts:")
print(df.Gender.value_counts())

# sort_values is the series/column -----------------------
print("\n\n Discipline cols")
print(df.Discipline)

print("\n sort Discipline values:")
sortedbyjobs=df.Discipline.sort_values(axis=0, ascending=True, inplace=False, kind='quicksort', na_position='last')
print(sortedbyjobs)

print()
print(df.sort_values(by=['Discipline','Medal']))




# boolean indexing --------------------------------------------------
# Boolean vectors can be used to filter data
print("\n Gold instances 0:")
df.Goldcol = df.Medal=="Gold" # prints a col of True or False, if the instance is married or not
print(df.Goldcol)

print("\n Gold instances 1:")
df.GoldItems = df[df.Medal=="Gold"] # only selects the married instances
print(df.GoldItems)

print("\n Gold instances 2:")
df.MenGoldist = df[(df.Medal=="Gold") & (df.Gender=="Men")] # only selects the men goldist instances, include the condition in bracket, and define &
print(df.MenGoldist)


# stering handling --------------------------------------------------
# Series.str access values of series as strings and apply several methods to it
# Series.str.contains() -  Series.str.startwith() - Series.str.isnumeric()



