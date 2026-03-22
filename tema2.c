#include <windows.h>
#include <stdio.h>

int main() {
    HKEY hKey;              // h Handle
    LPCSTR lpszSubKey = "Control Panel"; // lpsz Long Pointer to String Zero-terminated
    LONG lResult;           // l Long
    
    lResult = RegOpenKeyExA(HKEY_CURRENT_USER, lpszSubKey, 0, KEY_READ, &hKey);

    if (lResult == ERROR_SUCCESS) {
        char szSubKeyName[255]; // sz String Zero-terminated (char array)
        DWORD dwNameSize;       // dw Double Word (32-bit unsigned)
        DWORD dwIndex = 0;      // dw Double Word
        FILETIME ftLastWrite;   // ft FileTime structure

        printf("Subkeys for HKEY_CURRENT_USER\\%s:\n\n", lpszSubKey);

        dwNameSize = sizeof(szSubKeyName);
        
        // RegEnumKeyExA returns ERROR_SUCCESS as long as subkeys exist
        while (RegEnumKeyExA(hKey, dwIndex, szSubKeyName, &dwNameSize, NULL, NULL, NULL, &ftLastWrite) == ERROR_SUCCESS) {
            printf("[%lu] %s\n", dwIndex, szSubKeyName);
            
            // reset the buffer for the next itteration 
            dwNameSize = sizeof(szSubKeyName);
            dwIndex++;
        }

        RegCloseKey(hKey);
    } else {
        printf("Error opening key. Code: %ld\n", lResult);
    }

    return 0;
}