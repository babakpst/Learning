def get_df(yr):
    return pd.read_csv("../../inputs/Environmental_Data_Deep_Moor_{}.csv".format(yr))