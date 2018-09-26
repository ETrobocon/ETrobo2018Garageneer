#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
PyFingerprint
Copyright (C) 2015 Bastian Raschke <bastian.raschke@posteo.de>
All rights reserved.

"""

import hashlib
from pyfingerprint.pyfingerprint import PyFingerprint


## Search for a finger
##

## Tries to initialize the sensor
try:
    f = PyFingerprint('/dev/ttyUSB0', 57600, 0xFFFFFFFF, 0x00000000)

    if ( f.verifyPassword() == False ):
        raise ValueError('The given fingerprint sensor password is wrong!')

except Exception as e:
    print('The fingerprint sensor could not be initialized!')
    print('Exception message: ' + str(e))
    exit(1)

## Gets some sensor information
print('Currently used templates: ' + str(f.getTemplateCount()) +'/'+ str(f.getStorageCapacity()))

## Tries to search the finger and calculate hash
try:
    print('Waiting for finger...')
    
    #import time
    ## Wait that finger is read
    while ( f.readImage() == False ):
        pass
    
    ## Converts read image to characteristics and stores it in charbuffer 1
    f.convertImage(0x01)

    ## Searchs template
    result = f.searchTemplate()

    positionNumber = result[0]
    accuracyScore = result[1]
    
    ## enroll mode
    if ( positionNumber == -1 ):
        print('No match found!')
        print('========== [Start] _ Enroll Mode ==========')
        set_mode = 0
        
        ## Creates a template
        f.createTemplate()

        ## Saves template at new position number
        positionNumber = f.storeTemplate()
        print('Finger enrolled successfully!')
        print('New template position #' + str(positionNumber))
        
        path = 'list.txt'
        with open(path, mode='w') as f:
            f.write(str(set_mode) +'\n' +str(positionNumber))
        f.close()

        exit(0)
        print('========== [End] _ Enroll Mode ==========')
        
    ## delete mode    
    else:
        print('********** [Start] _ Delete Mode **********')
        set_mode = 1
  
        print('Found template at position #' + str(positionNumber))
        print('The accuracy score is: ' + str(accuracyScore))
        
        if ( f.deleteTemplate(positionNumber) == True ):
            print('Template deleted!')
            path = 'list.txt'
            with open(path, mode='w') as f:
                f.write(str(set_mode) +'\n' +str(positionNumber))
            f.close()
        
        else:
            pritn('Delete Error')
            
        print('********** [End] _ Delete Mode **********')

    ## OPTIONAL stuff
    ##

    ## Loads the found template to charbuffer 1
    ##f.loadTemplate(positionNumber, 0x01)

    ## Downloads the characteristics of template loaded in charbuffer 1
    ##characterics = str(f.downloadCharacteristics(0x01)).encode('utf-8')

    ## Hashes characteristics of template
    ##print('SHA-2 hash of template: ' + hashlib.sha256(characterics).hexdigest())

except Exception as e:
    print('Operation failed!')
    print('Exception message: ' + str(e))
    exit(1)
