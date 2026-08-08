#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

const int GPS_RX = 4;
const int GPS_TX = 3;

const int GSM_RX = 0;
const int GSM_TX = 1;

const int STATUS_LED = 13;

const uint32_t GPS_BAUD = 9600;
const uint32_t GSM_BAUD = 9600;

const char TRACK_COMMAND[] = "Track Vehicle";
const char PHONE_NUMBER[] = "+91XXXXXXXXXX";

TinyGPSPlus gps;
SoftwareSerial gpsSerial(GPS_RX, GPS_TX);

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

bool trackingRequested = false;


void setup()
{
    pinMode(STATUS_LED, OUTPUT);
    digitalWrite(STATUS_LED, LOW);

    Serial.begin(GSM_BAUD);
    gpsSerial.begin(GPS_BAUD);

    lcd.begin(16, 2);

    showMessage("Vehicle Tracking", "System Starting");
    delay(2000);

    initializeGSM();

    showMessage("GPS Initializing", "Please Wait");
    delay(2000);

    showMessage("System Ready", "Waiting for SMS");
}


void loop()
{
    readGSMCommand();

    while (trackingRequested)
    {
        while (gpsSerial.available())
        {
            gps.encode(gpsSerial.read());

            if (gps.location.isUpdated())
            {
                sendLocation();
                trackingRequested = false;
                break;
            }
        }

        if (Serial.available())
        {
            readGSMCommand();
        }
    }
}


void readGSMCommand()
{
    if (!Serial.available())
        return;

    String message = Serial.readString();

    message.trim();

    if (message.indexOf(TRACK_COMMAND) >= 0)
    {
        trackingRequested = true;

        showMessage("Tracking", "Getting GPS...");
    }
}


void initializeGSM()
{
    showMessage("GSM", "Initializing...");

    sendATCommand("AT", 1000);
    sendATCommand("ATE0", 1000);
    sendATCommand("AT+CMGF=1", 1000);
    sendATCommand("AT+CNMI=2,2,0,0,0", 1000);

    showMessage("GSM Ready", "Waiting Network");
    delay(2000);
}


void sendLocation()
{
    if (!gps.location.isValid())
    {
        showMessage("GPS Error", "No Location");
        return;
    }

    digitalWrite(STATUS_LED, HIGH);

    String latitude = String(gps.location.lat(), 6);
    String longitude = String(gps.location.lng(), 6);

    String message =
        "Vehicle Location\n"
        "Latitude: " + latitude +
        "\nLongitude: " + longitude +
        "\nhttps://maps.google.com/?q=" +
        latitude + "," + longitude;

    sendSMS(message);

    showMessage("Location Sent", "SMS Delivered");

    delay(2000);

    digitalWrite(STATUS_LED, LOW);

    showMessage("System Ready", "Waiting for SMS");
}


void sendSMS(const String &message)
{
    Serial.println("AT+CMGF=1");
    delay(500);

    Serial.print("AT+CMGS=\"");
    Serial.print(PHONE_NUMBER);
    Serial.println("\"");

    delay(500);

    Serial.print(message);

    delay(300);

    Serial.write(26);

    delay(3000);
}


void sendATCommand(const char *command, unsigned long waitTime)
{
    Serial.println(command);
    delay(waitTime);

    while (Serial.available())
    {
        Serial.read();
    }
}


void showMessage(const char *line1, const char *line2)
{
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print(line1);

    lcd.setCursor(0, 1);
    lcd.print(line2);
}
