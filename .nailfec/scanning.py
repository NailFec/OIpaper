import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle
from matplotlib import rcParams

rcParams["font.family"] = "Consolas"
fig, ax = plt.subplots(figsize=(8, 8))
limit = 16

# y = x
x_values = range(0, limit+1)
y_values = x_values
plt.plot(x_values, y_values, linestyle='dashed', color='gray')

# rectangles
rectangles = [ # (left-down)(x, y), width, height
	(6, 6, 6, 6, 'pink', 'now'),
	(6, 0, 6, 6, 'lightgreen', 'answer')
]
for x, y, width, height, fillColor, label in rectangles:
	rect = Rectangle((x, y), width, height, edgecolor='none', facecolor=fillColor, linewidth=2)
	ax.add_patch(rect)
	plt.text(x + width / 2, y + height / 2, label, color='black', ha='center', va='center', fontsize=14)

# spaces = [
# 	(0, 0, 10, 6, 'yellow', 4),
# 	(0, 0, 6, 6, 'blue', 2)
# ]
# for x, y, width, height, edgeColor, lineWidth in spaces:
# 	rect = Rectangle((x, y), width, height, edgecolor=edgeColor, facecolor='none', linewidth=lineWidth,
# 	                 linestyle='dashed')
# 	ax.add_patch(rect)

# points
points = [(1, 0), (2, 0), (3, 1), (4, 0), (5, 0), (6, 5), (7, 4), (8, 0), (9, 2), (10, 3), (11, 8), (12, 11), (13, 12), (14, 9), (15, 7)]
for x, y in points:
	plt.scatter(x, y, color='black', s=25)
	plt.text(x + 0.1, y + 0.1, f'({x},{y})', fontsize=10, color='black', ha='left', va='bottom')

plt.xlim(0, limit)
plt.ylim(0, limit)
plt.xticks(range(0, limit + 1, 2))
plt.yticks(range(0, limit + 1, 2))
plt.xlabel('index')
plt.ylabel('bef[i]')

plt.grid(True)

plt.show()
