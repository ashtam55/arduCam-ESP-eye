#include <Arduino.h>

#include <WiFi.h>
#include "./file.h"
#include "camera.h"
#include "lapse.h"
#include <soc/soc.h>
#include<soc/rtc_cntl_reg.h>

const char *ssid = "91springboard";
const char *password = "";

void startCameraServer();

void setup()
{
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG,0);
	Serial.begin(115200);
	Serial.setDebugOutput(true);
	Serial.println();
	initFileSystem();
	initCamera();

	WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}
	Serial.println("");
	Serial.println("WiFi connected");
	startCameraServer();
	Serial.print("Camera Ready! Use 'http://");
	Serial.print(WiFi.localIP());
	Serial.println("' to connect");
}

void loop()
{
	unsigned long t = millis();
	static unsigned long ot = 0;
	unsigned long dt = t - ot;
	ot = t;
	processLapse(dt);
}
