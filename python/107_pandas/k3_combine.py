

# babak poursartip
# 09/23/2023


import pandas as pd

#CA = pd.read_csv("./data/.csv", index_col=0)
ds_Ca = pd.read_csv("./data/CAvideos.csv")
ds_GB = pd.read_csv("./data/GBvideos.csv")

print(ds_Ca.head())
print(f" num of entries: {ds_Ca.shape[0]}")

print(ds_GB.head())
print(f" num of entries: {ds_GB.shape[0]}")

print("columns")
print(ds_GB.columns)


# describe(): it is a summary function for numerical data. It is type-aware (output changes based on the data type of the input)
print("1++++++++ ") # concat: adds two dataframe/series when data in different DataFrame or Series objects but having the same fields (columns)

concatenated = pd.concat([ds_Ca, ds_GB])

print(concatenated.head())
print(f" num of entries: {concatenated.shape[0]}")

print("2++++++++ ") # join() lets you combine different DataFrame objects which have an index in common.

left = ds_Ca.set_index(['title', 'trending_date'])
right = ds_GB.set_index(['title', 'trending_date'])

joined = left.join(right, lsuffix='_CAN', rsuffix='_UK')

print(joined.head())






















