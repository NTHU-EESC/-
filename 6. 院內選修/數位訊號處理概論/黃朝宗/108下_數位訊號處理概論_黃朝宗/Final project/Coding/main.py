#!/usr/bin/env python
# coding: utf-8

# In[31]:


import numpy as np
import matplotlib
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

# Parameter Setup
N_type = 5
N_slice = 3
N_data = 100
N_clip = N_type*N_slice*N_data

duration = 30

oct_diff = np.array([0, 200, 400, 800, 1600, 3200, 6400, 11025])  # Freq Normalized interval
oct_alpha = 0.02;  # tunable

N_freq_intvl = (len(oct_diff)-1);
feature = np.zeros((N_clip, N_freq_intvl*2))
style = np.zeros((N_clip, 1));


# In[74]:


from scipy.io import wavfile
from skimage.restoration import (denoise_wavelet, estimate_sigma)

# Visualization of one music clip
path = "Data/genres_original/classical/classical.00000.wav"
fs, y = wavfile.read(path)
N_y = y.shape[0]

y = y/max(y)

y_de = denoise_wavelet(y, wavelet='db1', mode='soft', method='BayesShrink', rescale_sigma='True')

# Time domain
fig, ax = plt.subplots()
plt.plot(np.arange(N_y)/N_y*duration, y)
ax.set_xlabel('Time')
ax.set_ylabel('Magnitude')
ax.set_title('Music Signals in Time Domain')
# fig, ax = plt.subplots()
# plt.plot(np.arange(N_y)/N_y*duration, y_de)
# ax.set_xlabel('Time')
# ax.set_ylabel('Magnitude')
# ax.set_title('Music Signals in Time Domain')


# In[75]:


# Frequency domain
from scipy.fftpack import fft,ifft
Y = fft(y)
Y_de = fft(y_de)
fig, ax = plt.subplots()
plt.plot(2*(np.arange(N_y)/N_y)-1, abs(Y))
ax.set_xlabel('Frequecny (Normalized)')
ax.set_ylabel('Magnitude')
ax.set_title('Music Signals in Frequency Domain')
# fig, ax = plt.subplots()
# plt.plot(2*(np.arange(N_y)/N_y)-1, abs(Y_de))
# ax.set_xlabel('Frequecny (Normalized)')
# ax.set_ylabel('Magnitude')
# ax.set_title('Music Signals in Frequency Domain')


# In[34]:


def oct_feature(start, stop, Y, alpha):
    N = Y.shape[0]
    Y_filter = Y[int(np.floor(N*start)):int(np.floor(N*stop))]
    N_filter = Y_filter.shape[0]
    Y_sort = np.sort(abs(Y_filter))
    N_avg = int(np.floor(N_filter*alpha))
    peak = np.sum(Y_sort[N_filter-N_avg:N_filter])/N_avg
    valley = np.sum(Y_sort[0:N_avg])/N_avg
    sc = peak - valley
    return peak, valley, sc


# In[66]:


data_type = ["classical", "country", "blues", "hiphop", "pop"]

# Sliced to 5 clip
data_diff = np.array([0, 5, 10, 15, 20, 25, 30])/30    # Time Normalized interval
Y_avg = np.zeros((N_type, int(N_y/3)))   # Time Normalized interval

# Sliced to 3 clip
data_diff = np.array([0, 10, 20, 30])/30    # Time Normalized interval
Y_avg = np.zeros((N_type, int(N_y/3)))   # Time Normalized interval

# Don't be sliced
# data_diff = np.array([0, 30])/30    
# Y_avg = np.zeros((N_type, N_y))

i_num = 0
for i in data_type:
    print("Now processing " + i)
    for j in range(N_data):
        if j < 10:
            num = "0"+str(j)
        else:
            num = str(j)
        path = "Data/genres_original/"+i+"/"+i+".000"+num+".wav"
        [fs, y] = wavfile.read(path)
        if y.shape[0] < N_y :
            z = np.zeros((N_y - y.shape[0]))
            y = np.concatenate((y, z), axis=0)
        for k in range(N_slice):
            y_slice = y[int(np.floor(N_y*data_diff[k])):int(np.floor(N_y*data_diff[k+1]))]
            y_slice = y_slice/max(y_slice)
            #y_de = denoise_wavelet(y_slice, wavelet='db1', mode='soft', method='BayesShrink', rescale_sigma='True')
            Y = fft(y_slice)
            #Y = fft(y_de)
            N_y_slice = Y.shape[0]
            Y_avg[i_num,:] = Y_avg[i_num,:] + abs(Y[:])
            # Octave-Scale Filter
            oct_diff_norm = oct_diff/(fs/2);  # Normalized interval
            sc = np.zeros((1,N_freq_intvl))
            valley = np.zeros((1,N_freq_intvl))
            peak = np.zeros((1,N_freq_intvl))
            for m in range(oct_diff.shape[0]-1):
                [peak[0,m], valley[0,m], sc[0,m]] = oct_feature(oct_diff_norm[m], oct_diff_norm[m+1], Y[int(np.floor(N_y_slice/2)):N_y_slice], oct_alpha)
            feature[i_num*N_data*N_slice+j*N_slice+k,0:N_freq_intvl] = sc
            feature[i_num*N_data*N_slice+j*N_slice+k,N_freq_intvl:2*N_freq_intvl] = valley
            style[i_num*N_data*N_slice+j*N_slice+k,0] = i_num    
            
    Y_avg[i_num,:] = Y_avg[i_num,:]/(N_data*N_slice)         
    i_num = i_num + 1


# In[414]:


np.savetxt("feature_.csv", feature, delimiter=",")
np.savetxt("style_.csv", style, delimiter=",")


# In[67]:


fig, ax = plt.subplots(figsize=(10,5))
for i in range(N_type):
    plt.plot(2*(np.arange(Y_avg[i,:].shape[0])/Y_avg[i,:].shape[0])-1, Y_avg[i,:]/(N_data*N_slice))
    ax.set_xlabel('Frequecny (Normalized)')
    ax.set_ylabel('Magnitude')
    ax.set_title('Avg FFT in different type music')
    ax.legend(data_type,loc="best")


# In[69]:


feature = np.array(feature)

size = (feature.shape[1])/2
labels = np.arange(size)+1;
type1 = feature[0:N_slice*N_data,:]
type2 = feature[N_slice*N_data:2*N_slice*N_data,:]
type3 = feature[2*N_slice*N_data:3*N_slice*N_data,:]
type4 = feature[3*N_slice*N_data:4*N_slice*N_data,:]
type5 = feature[4*N_slice*N_data:5*N_slice*N_data,:]
    
x = np.arange(len(labels))*3  # the label locations
width = 0.5  # the width of the bars
    
fig, ax = plt.subplots(figsize=(10,5))
rects1 = ax.bar(x - 2*width, np.mean(type1[:,0:7], axis=0), width, label='classical')
rects2 = ax.bar(x - width  , np.mean(type2[:,0:7], axis=0), width, label='country')
rects3 = ax.bar(x          , np.mean(type3[:,0:7], axis=0), width, label='blues')
rects4 = ax.bar(x + width  , np.mean(type4[:,0:7], axis=0), width, label='hiphop')
rects5 = ax.bar(x + 2*width, np.mean(type5[:,0:7], axis=0), width, label='pop')
    
# Add some text for labels, title and custom x-axis tick labels, etc.

ax.set_ylabel('Magnitude')
ax.set_title('SC Features in Different Types')
ax.set_xticks(x)
ax.set_xticklabels(labels)
ax.legend()
            
fig.tight_layout()
plt.show()

fig, ax = plt.subplots(figsize=(10,5))
rects1 = ax.bar(x - 2*width, np.mean(type1[:,7:14], axis=0), width, label='classical')
rects2 = ax.bar(x - width  , np.mean(type2[:,7:14], axis=0), width, label='country')
rects3 = ax.bar(x          , np.mean(type3[:,7:14], axis=0), width, label='blues')
rects4 = ax.bar(x + width  , np.mean(type4[:,7:14], axis=0), width, label='hiphop')
rects5 = ax.bar(x + 2*width, np.mean(type5[:,7:14], axis=0), width, label='pop')
    
# Add some text for labels, title and custom x-axis tick labels, etc.
ax.set_xlabel('Feature No.')
ax.set_ylabel('Magnitude')
ax.set_title('Valley Features in Different Types')
ax.set_xticks(x)
ax.set_xticklabels(labels)
ax.legend()
            
fig.tight_layout()
plt.show()


# In[70]:


#read file
# X = np.array(pd.read_csv('feature.csv',header=None))
# y = np.array(pd.read_csv('style.csv', header=None))

X = feature
y = style

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state=1, stratify = y)

sc = StandardScaler()
sc.fit(X_train)
X_train_std = sc.transform(X_train)
X_test_std = sc.transform(X_test)

from sklearn.decomposition import PCA
pca = PCA(n_components=14)
X_train_pca = pca.fit_transform(X_train_std)
X_test_pca = pca.transform(X_test_std)


# In[71]:


from sklearn.svm import SVC
svm = SVC(kernel='rbf', C=1000.0, random_state=1)
svm.fit(X_train_std, y_train.ravel())
print('SVM Accuracy: %.4f' %svm.score(X_test_std, y_test.ravel()))


# In[73]:


from sklearn.metrics import confusion_matrix
y_pred = svm.predict(X_test_std)
c = confusion_matrix(y_test.ravel(), y_pred)/int(y_test.shape[0]/N_type)*100
print(c)


# In[505]:


from skimage.restoration import (denoise_wavelet, estimate_sigma)

# Denoising Testing
res = 1000  # Resolution
fs = 5   # Frequency
t = 3     # Duration
n = np.arange(t*res)
s = np.cos(2*np.pi*fs*(n/res))

w = np.random.rand(t*res)-0.5
x = s + w
r = denoise_wavelet(x, wavelet='db1', mode='soft', method='BayesShrink', rescale_sigma='True')

# Time domain
fig, ax = plt.subplots()
plt.plot(n/(res), s)
plt.plot(n/(res), x)
plt.plot(n/(res), r)
ax.set_xlabel('Time')
ax.set_ylabel('Magnitude')
ax.set_title('Sin wave in Time Domain')

# Frequency domain
S = fft(s)
X = fft(x)
R = fft(r)
fig, ax = plt.subplots()
plt.plot((2*(n/(res*t))-1)*fs, abs(S))
plt.plot((2*(n/(res*t))-1)*fs, abs(X))
plt.plot((2*(n/(res*t))-1)*fs, abs(R))
ax.set_xlabel('Frequecny (Normalized)')
ax.set_ylabel('Magnitude')
ax.set_title('Music Signals in Frequency Domain')

