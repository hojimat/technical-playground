import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from funcs import remove_outliers
# Read data
data = pd.read_csv('data/train.csv')

# Prepare data
data.dropna(inplace=True)

data = remove_outliers(data, 'RoomService')
data = remove_outliers(data, 'FoodCourt')
data = remove_outliers(data, 'ShoppingMall')
data = remove_outliers(data, 'Spa')
data = remove_outliers(data, 'VRDeck')

data = data[
    (data['RoomService'] < data['RoomService'].quantile(0.99)) &
    (data['RoomService'] < data['FoodCourt'].quantile(0.99)) &
    (data['RoomService'] < data['ShoppingMall'].quantile(0.99)) &
    (data['RoomService'] < data['Spa'].quantile(0.99)) &
    (data['RoomService'] < data['VRDeck'].quantile(0.99))
]

data.hist()
plt.show()
# Prepare regression
X = data[['Age', 'CryoSleep']]
y = data['Transported']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=94)


# Fitting and Prediction
clf = LogisticRegression().fit(X_train,y_train)
y_pred = clf.predict(X_test)

# Result Metrics
accuracy = sum(y_pred==y_test) / len(y_test)
precision = (y_pred & y_test).sum() / sum(y_pred)
print(f"Accuracy: {accuracy}")
print(f"Precision: {precision}")


# Export results
#output = pd.DataFrame({'PassengerId': data.loc[y_test.index, 'PassengerId'], 'Transported': y_pred})
#output.to_csv('logit.csv', index=False)
