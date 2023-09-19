

# babak poursartip
# 07/30/2023


# Index-based selection: iloc[row, col]; selecting data in a dataframe base on its index/numerical position.
# label-based selection: loc[row, col]; selecting based on the data index value and not its position.

# When we use iloc we treat the dataset like a big matrix (a list of lists), one that we have to index into by position. loc, by contrast, uses the information in the indices to do its work.

import pandas as pd

bank = pd.read_csv("./data/BankMarketingData.csv")

print(bank.head())

print("1--")
print(bank.iloc[:,0]) # everything in row, and first col

print("2--")
print(bank.iloc[0:3,0]) # first three numbers in row (excluding 3), and first col

print("3--")
print(bank.iloc[1:3,2]) # first two numbers in row, and first col


print("4--")
print(bank.iloc[[1,5,10,11],2]) # rows from the list, and first col

print("4--")
print(bank.iloc[-5:,0]) # last five rows, and first col


print("5====")
#print(bank.loc[:,0]) # last five rows, and first col ----> error
#print(bank.iloc[1:8,"age"]) # last five rows, and discipline col  ----> error
print(bank.loc[:,"age"]) # last five rows, and age col
print(bank.loc[1:8,"age"]) # last five rows, and discipline col


print("6====")
bankold = bank.loc[bank.age>=60]
print(bankold)

print("7====")
bankold2 = bank.loc[ (bank.age>=60) & (bank.job.isin(["admin.","retired"]))]
print(bankold2)




