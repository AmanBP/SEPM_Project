def encryptDecrypt(inpString): 
    xorKey = 'P'; 
    length = len(inpString);  
    for i in range(length): 
        inpString = (inpString[:i] + chr(ord(inpString[i]) ^ ord(xorKey)) + inpString[i + 1:]);
    return inpString; 