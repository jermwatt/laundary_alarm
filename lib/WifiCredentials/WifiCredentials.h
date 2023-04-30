#ifndef WiFiCredentials_h
#define WiFiCredentials_h

#include <EEPROM.h>

const int SSID_ADDR = 0;
const int PASSWORD_ADDR = 32;

class WiFiCredentials {
  public:
    void saveCredentials(const char* ssid, const char* password) {
      for (int i = 0; i < strlen(ssid); ++i) {
        EEPROM.write(SSID_ADDR + i, ssid[i]);
      }
      for (int i = 0; i < strlen(password); ++i) {
        EEPROM.write(PASSWORD_ADDR + i, password[i]);
      }
      EEPROM.commit();
    }

    const char* getSSID() {
      char* ssid = new char[32];
      for (int i = 0; i < 32; ++i) {
        ssid[i] = EEPROM.read(SSID_ADDR + i);
      }
      return ssid;
    }

    const char* getPassword() {
      char* password = new char[64];
      for (int i = 0; i < 64; ++i) {
        password[i] = EEPROM.read(PASSWORD_ADDR + i);
      }
      return password;
    }
};

#endif