def monthly_avg_calc(mo,col):
    return df[df['date'].str.contains('201[2345]_[0]?'+ str(mo))][col].mean()
