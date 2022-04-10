
    Author    KMS - Martin Dubois, P. Eng.
    Copyright (C) 2022 KMS
    License   http://www.apache.org/licenses/LICENSE-2.0
    Product   TWS - CPP
    File      INJEC_Firmware/INJEC_Firmware.ino

    ===== Montage materiel ==================================================

Pour ce projet vous devez avoir une carte compatible avec l'IDE arduino et un
senseur d'humidite et de temperature base sur un DHT22.

Le projet a ete teste avec une carte Arduino UNO R3.

Le senseur comporte 3 pins:

    GND pour la mise a la terre
    VCC pour l'alimentation
    DAT pour la ligne de communciation

Chacune de ces PIN doivent etre connecte a la carte arduino.

    GND a une des pin GND du arduino
    VCC a la pin 3.3 V du arduino
    DAT a la pin digical numero 2 du arduino

    ===== Installation de la librairie ======================================
    [ ] Lancer l'IDE Arduino
        - Dans le menu "Tool", selectionner l'item "Manage Libraries".
            - Dans la boite de recherche, entrer "DHT22" et appuyer sur la
              touche "ENTER"
            - Trouver la librairie nommee "DHT sensor library by Adafruit"
              (Le projet a ete teste avec le version 1.4.3)
            - Cliquer sur "Install"

    ===== Compilation et programmation ======================================
    [ ] Connecter la carte arduino a votre ordinateur en utilisant un cable
        USB.
    [ ] Ouvrez le "Device Manager" de Windows
        - Dans la section "Ports (COM & LPT)", identifier le port associe a
          la carte arduino et le noter.
    [ ] Lancer l'IDE Arduino en double cliquant sur le fichier
        "INJEC_Firmware.ino"
        - Dans le menu "tool", selectionner l'item "Board" et selectionner la
          carte utilisee.
        - Dans le menu "tool", selectionner l'item "Port" et selectionner le
          port associe a votre carte.
        - Dans le menu "Sketch", selectionner l'item "Upload"
        