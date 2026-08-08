# GPS-GSM Vehicle Tracking System

An embedded vehicle tracking system that uses GPS for location detection and GSM for remote communication.

The system is built around an Arduino UNO and integrates a GPS module, GSM modem and 16×2 LCD to obtain vehicle coordinates and communicate the location to a remote user through SMS.

## Overview

Vehicle tracking requires a way to determine the current position of a vehicle and communicate that information remotely.

This project combines GPS positioning with GSM communication to provide a simple, low-cost vehicle tracking solution.

The GPS module obtains the geographical coordinates of the vehicle. The Arduino processes the location data and uses the GSM modem to send the coordinates to the registered user through SMS.

The received latitude and longitude can then be used to identify the vehicle location on a map.

## System Architecture

                 GPS Satellites
                       |
                       v
                  GPS Module
                       |
                Latitude / Longitude
                       |
                       v
                  Arduino UNO
                   /        \
                  /          \
                 v            v
             16×2 LCD     GSM Module
                              |
                              v
                        GSM Network
                              |
                              v
                         Remote User
                              |
                              v
                         Map / GPS
## Hardware
Arduino UNO
GPS module
SIM900A GSM module
16×2 LCD
SIM card
GPS antenna
Power supply
Connecting wires and supporting components
Software
Arduino IDE
Embedded C/C++
TinyGPS++ library
SoftwareSerial
LiquidCrystal
GSM AT commands

## Working Principle
The GPS module receives positioning information from GPS satellites.
The GPS data is received by the Arduino.
The controller extracts the vehicle's latitude and longitude.
The location can be displayed on the 16×2 LCD.
The GSM module is initialized and connected to the cellular network.
The system waits for a tracking request.
When the Track Vehicle command is received, the latest valid GPS coordinates are obtained.
The coordinates are sent to the remote user through SMS.
The received coordinates can be used to locate the vehicle on a map.

## Tracking Flow

Start
  |
  v
Initialize Arduino
  |
  v
Initialize GPS
  |
  v
Initialize GSM
  |
  v
Wait for "Track Vehicle"
  |
  v
Read GPS Data
  |
  v
Extract Coordinates
  |
  v
Display Location
  |
  v
Send Coordinates through SMS
  |
  v
Remote User
  |
  v
Repeat

## GPS Data

The GPS receiver provides positioning information through serial communication.

## The implementation processes GPS data to obtain:

Latitude
Longitude
Position information

The location information is then formatted for transmission through GSM.

## GSM Communication

The GSM modem communicates with the Arduino through serial communication and is controlled using AT commands.

The system uses SMS communication to send the vehicle location to the registered user.

## The tracking request used by the system is:

Track Vehicle
Key Features
GPS-based vehicle positioning
GSM-based SMS communication
Arduino-based embedded control
Latitude and longitude extraction
Local LCD display
On-demand vehicle tracking
Map-compatible location information
Applications

## The system can be used as a basic foundation for:

Vehicle tracking
Fleet monitoring
School and college bus tracking
Transportation monitoring
Vehicle security
Asset tracking
Logistics monitoring
Advantages
Simple embedded implementation
Combines GPS and GSM technologies
Low-cost tracking approach
Remote location reporting
Easy to extend with additional sensors and communication features
Limitations
GPS accuracy depends on satellite visibility and environmental conditions.
GSM operation depends on cellular network availability.
SMS-based communication is not equivalent to continuous internet-based tracking.
The system requires an external power source when installed in a vehicle.
Future Improvements

## Possible extensions include:

Real-time web-based tracking
Mobile application integration
IoT cloud connectivity
GPS route history
Geofencing
Vehicle speed monitoring
Accident detection
Emergency alerts
Fleet management dashboard
Continuous location logging

## Source Code

The source/ directory contains the Arduino implementation of the tracking system.

The implementation is organized around GPS data acquisition, location processing, GSM communication and LCD display.

## Project Information

Project: GPS-GSM Vehicle Tracking System

Domain: Embedded Systems / GPS / GSM / Wireless Communication

Controller: Arduino UNO

GPS: GPS receiver module

Communication: GSM / SMS

Display: 16×2 LCD

Project Type: Academic Embedded Systems Project

Reference

This project was developed with reference to existing GPS and GSM based vehicle-tracking system designs.

The referenced design describes an Arduino UNO based system integrating GPS, GSM and LCD for vehicle-location tracking and SMS-based reporting.
