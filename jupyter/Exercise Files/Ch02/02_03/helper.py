import pandas as pd
df = pd.read_csv("../../inputs/Environmental_Data_Deep_Moor_2015.csv")

def get_day(d):
  return df[df['date']==d]
