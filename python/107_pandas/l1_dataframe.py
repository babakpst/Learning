
# babak poursartip
# June 30, 20223


import pandas as pd

#df = pd.read_csv('data/BankMarketingData.csv')
#df = pd.read_csv('data/SummerOlympicmedallists1896to2008-IOCCOUNTRYCODES.csv')
df = pd.read_csv('data/olympics.csv',skiprows=4)


# info --------------------------------------------------------------
print(df.head(5))
#df.head(5) # not working if it is not in the jupyter

print("\n >>>> info: ")
df.info() # returns general info about the dataframe

print("\n >>>>>>description: ")
print(df.describe()) # general info about numerical features/columns

# value_counts ------------------------------------------------------
# it returns a series object counting all the unique values. The first value is the most recurring element. The second element is the second most recurring element.
print("----------")
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
print("\n string series")
print("1: \n",df.Athlete.str.contains("Florence"))
print("2: \n",df[df.Athlete.str.contains("Florence")])
print("3: \n",df[df.Athlete.str.contains("Florence")].to_string())

# some cool details about the dataset -------------------------------
print("\n\n cool facts: ")
print(df[df.Athlete=="OWENS, Jesse"].to_string())

print("\n")
print(df.columns)
print(df[(df.Medal=="Gold") & (df.Discipline=="Badminton")& (df.Event=="singles")].to_string())
print(df[(df.Medal=="Gold") & (df.Discipline=="Badminton")& (df.Event=="singles")].NOC.value_counts())
print("country with the most singles badminton: ",df[(df.Medal=="Gold") & (df.Discipline=="Badminton")& (df.Event=="singles")].NOC.value_counts().index[0])

# three countries with most medals in 1984~2008

print("\n")
print(df[(df.Edition>=1984) & (df.Edition <=2008)].NOC.value_counts())
print("three countries with most medals in 1984~2008:",  df[(df.Edition>=1984) & (df.Edition <=2008)].NOC.value_counts().index[0:3])

# male gold medal winners for the 100m track and field sprint
print()
# print(df[(df.Gender=="men") & (df.Event == Any) ])
print(df[(df.Gender=="Men") & (df.Medal=="Gold") & (df.Event== "100m")  ].to_string())
print(df[(df.Gender=="Men") & (df.Medal=="Gold") & (df.Event== "100m")  ].sort_values("Edition", ascending=False)[['City', 'Edition', "Athlete" ]])
