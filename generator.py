import random

how_many_numbers = 100 

l = []
for i in range(10000):
    l.append(random.randint(-10, 500))

my_final_list = []
[my_final_list.append(n) for n in l if n not in my_final_list]


for i in range(how_many_numbers):
    print(my_final_list[i], end=" ")