

# babak poursartip
# 09/19/2023


import pandas as pd

bank = pd.read_csv("./data/BankMarketingData.csv")

print(bank.head())


# describe(): it is a summary function for numerical data. It is type-aware (output changes based on the data type of the input)
print("1++++++++ summary function for numerical data")
print(bank.describe())

print("2++++++++ describe for a single function")
print(bank.age.describe())

print("3++++++++ individual funcitons for each col")
print(f" mean of age:   {bank.age.mean()}")
print(f" max of age:    {bank.age.max()}")
print(f" min of age:    {bank.age.min()}")
print(f" count of age:  {bank.age.count()}")
print(f" std of age:    {bank.age.std()}")

# .unique() + .nunique(): finds unique valuese in the col/series
print("4++++++++ unique items of a col (mainly for object features)")
print(f" number of unique items in job: {bank.job.nunique()}")
print(f" unique items in job: \n {bank.job.unique()}")

# value_counts(): counts how many times each value has been repeated in a col/series
print("5++++++++ ")
print(f" items in job: \n {bank.job.value_counts()}")


# map (equivalent to apply): Note that map() and apply() return new, transformed Series and DataFrames, respectively. They don't modify the original data they're called on.
print("6++++++++ ")
print(f" col names: \n {list(bank.columns)}")

meanOfage = bank.age.mean()
print(f"before normalizaing age: \n {bank.age}")
#bank.age = bank.age.map(lambda p:p-meanOfage)

# approach 1
tmp = bank.age.map(lambda p:p-meanOfage)
print(f"after normalizaing age1: \n {tmp}")


# approach 2
def remean_age(row):
    row.age = row.age - meanOfage
    return row

tmp = bank.apply(remean_age, axis='columns')
print(f"after normalizaing age2: \n {tmp.age}")

# approach 3: fastest, it uses a library.
tmp = bank.age - bank.age.mean()
print(f"after normalizaing age3: \n {tmp}")


print("7====")
print(bank.groupby("marital")) # prints the datatype only: <pandas.core.groupby.generic.DataFrameGroupBy object at 0x7f86d9c21040>
#print(type(bank.groupby("marital"))) #
#print(bank.groupby("marital").points)

print("8====")
print(bank.groupby("marital").marital.count()) # equivalent to value_counts()
print()
print(f" items in marital: \n {bank.marital.value_counts()}")
print()
print(bank.groupby("marital").size()) # equivalent to the above statement.

print("9====")
print(bank.groupby("marital").age.max())

print("10====")
print(bank.groupby(["marital","education"]).age.count())
print(bank.groupby(["marital","education"]).age.max())

print("11====")
print(bank.groupby("marital").age.agg([min, max]))


print("12====") #sorting





