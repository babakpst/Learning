
def hours_dict(date):
    day = df[df['date']==date]
    hours = [time.split(':')[0] for time in day['time']]
    hours_dict = {i:hours.count(str(i)) for i in np.arange(24)}
    return hours_dict
