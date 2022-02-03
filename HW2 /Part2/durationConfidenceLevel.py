import numpy as np
from scipy.stats import t

data = np.loadtxt('/Users/josiahlin/Desktop/IoT/HW2 /Part2/duration.txt')
print(data, "size of data; ", len(data))
m = data.mean()
s = data.std()
length = len(data)
dof = data.size - 1
# 95% confidence level
confidence = 0.95
t_crit = np.abs(t.ppf((1-confidence)/2, dof))
confidence_level = (m - s*t_crit/np.sqrt(length),
                    (m + s*t_crit/np.sqrt(length)))
print(confidence_level)
