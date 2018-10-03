#!/home/samhaug/anaconda2/bin/python

'''
==============================================================================

File Name : h5_to_ascii.py
Purpose : ---
Creation Date : 03-10-2018
Last Modified : Wed 03 Oct 2018 05:36:46 PM EDT
Created By : Samuel M. Haugland

==============================================================================
'''

import numpy as np
import h5py


f = h5py.File('../synth_reverb.h5','r')

with open('reverb.txt','w') as t:
    for keys in f.keys()[0:2]:
        t.write('NEW'+'\n')
        t.write(keys+'\n')
        np.savetxt(t,f[keys]['coords'][:],fmt='%8.3f')
        t.write('ScSScS\n')
        np.savetxt(t,f[keys]['ScSScS'][:],fmt='%8.8f')
        t.write('ScSScSScS\n')
        np.savetxt(t,f[keys]['ScSScSScS'][:],fmt='%8.8f')
        t.write('sScS\n')
        np.savetxt(t,f[keys]['sScS'][:],fmt='%8.8f')
        t.write('sScSScS\n')
        np.savetxt(t,f[keys]['sScSScS'][:],fmt='%8.8f')
        t.write('sScSScSScS\n')
        np.savetxt(t,f[keys]['sScSScSScS'][:],fmt='%8.8f')

