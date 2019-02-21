import pandas as pd
import csv as csv


def csv_reader_pandas():
    df = pd.read_csv('csvfile.csv', delimiter=',')
    for i in df['Id']:
        if i > 1:
            print(i)
            print(df['First'][int(i - 1)])


def csv_reader():
    with open('csvfile.csv') as f:
        csv_reader = csv.reader(f, delimiter=',')
        rows = []
        for row in csv_reader:
            rows.append(list(row))

        for i in range(1, len(rows)):
            if int(rows[i][0]) > 1:
                print(rows[i][0])
                print(rows[i][1])


csv_reader_pandas()
csv_reader()
