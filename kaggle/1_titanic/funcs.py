import pandas as pd

def remove_outliers(data: pd.DataFrame, column: str):
    '''Function removes 99th and 1st percentile'''
    q01 = data[column].quantile(0.01)
    q99 = data[column].quantile(0.99)
    return data[(data[column] < q99) & (data[column] >= q01)]