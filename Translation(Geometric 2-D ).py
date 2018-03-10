
# coding: utf-8

# In[1]:


import matplotlib.pyplot as plt
import numpy as np
import re


# In[2]:


rasterSize = eval(input("Enter Raster Size: "))


# In[3]:


def printRaster():
    x_co = []
    y_co = []
    
    for i in range(-1*int(rasterSize/2),int(rasterSize/2),1):
        x_co.append(i)
        y_co.append(i)
    
    plt.grid()
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.plot(x_co, y_co, alpha=0.0)
    plt.plot([0,0], [-1*int(rasterSize/2),int(rasterSize/2)], color="black")
    plt.plot([-1*int(rasterSize/2),int(rasterSize/2)], [0,0], color="black")


# In[4]:


printRaster()
plt.show()


# In[5]:


x_list = []
y_list = []


# In[6]:


points = input("Enter coordinates: ")


# In[7]:


points.split(" ")


# In[8]:


counter = -1
temp = ''
index = -1
print(len(points))
for i in points:
    index += 1
    if re.match(r' ', i) or index == len(points)-1:
        if index == len(points)-1:
            temp += i
        i = temp
        temp = ''

        counter += 1
        if counter%2 == 0:
            x_list.append(int(i))
        else:
            y_list.append(int(i))
    else:
        temp += i


# In[9]:


x_list.append(x_list[0])


# In[10]:


y_list.append(y_list[0])


# In[11]:


printRaster()
plt.title("Object before Translation")
plt.plot(x_list, y_list, label="previous", marker='o', color='blue')
plt.legend()
plt.show()


# In[12]:


trans_x_list = []
trans_y_list = []


# In[13]:


tx = eval(input("Transfer towards x-axis: "))
ty = eval(input("Transfer towards y-axis: "))


# In[14]:


for i in x_list:
    trans_x_list.append(i+tx)


# In[15]:


for i in y_list:
    trans_y_list.append(i+ty)


# In[16]:


trans_x_list


# In[17]:


trans_y_list


# In[18]:


printRaster()

plt.title("2D Geometric Translation")
plt.plot(x_list, y_list, label="previous", marker='x', color='blue', linestyle='dotted')
plt.plot(trans_x_list, trans_y_list, label="after", marker='o', color='green')
plt.legend()
plt.show()

