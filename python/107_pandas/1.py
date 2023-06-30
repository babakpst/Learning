
# babak poursartip
# June 30, 20223


import pandas as pd

df = pd.read_csv('data/BankMarketingData.csv')


print(df.head(5))
#df.head(5) # not working if it is not in the jupyter

df.info() # returns general info about the dataframe

# value_counts
# it returns a series object counting all the unique values. The first value is the most recurring element. The second element is the second most recurring element.
print()
print(df.age.value_counts(normalize=False, sort=True, ascending=False, bins=None, dropna=True))
print(df.job .value_counts())
print(df.marital.value_counts())


# sort_values is the series/column
print()
jobs=df.job.sort_values(axis=0, ascending=True, inplace=False, kind='quicksort', na_position='last')
print(jobs)

print(df.sort_values(by=['age','marital']))

