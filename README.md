# Membership Management System

## Apžvalga
Šis projektas įgyvendina narystės valdymo sistemą su keliais posistemiais, kurie kartu tvarko įvairius narystės valdymo aspektus, įskaitant pranešimus, rinkodarą ir sąskaitų išrašymą.

## Sistemos Komponentai

### Pagrindiniai Komponentai
- **Membership**: Pagrindinė klasė, kuri tvarko narių informaciją ir veikia kaip stebėjimo modelio objektas
- **Observer**: Abstrakti bazinė klasė, kuri apibrėžia visų stebėtojų klasių sąsają

### Posistemiai

1. **Marketing System**
   - Tvarko rinkodaros operacijas
   - Įgyvendina stebėjimo modelį

2. **Billing System**
   - Tvarko sąskaitų operacijas
   - Įgyvendina stebėjimo modelį

3. **Notification System**
   - Įgyvendina stebėjimo modelį
   - Tvarko narių pranešimus
   - Šiuo metu kuriama :D
   - Bus testuojama su `notification_test` po užbaigimo

## Projekto Struktūra
```
├── CMakeLists.txt          # Surinkimo konfigūracija
├── Membership.h/cpp        # Pagrindinis narystės valdymas
├── Observer.h             # Stebėjimo modelio sąsaja
├── NotificationSystem.h/cpp # Pranešimų posistemė
├── MarketingSystem.h/cpp   # Rinkodaros posistemė
├── BillingSystem.h/cpp     # Sąskaitų posistemė
├── demo.cpp               # Demonstracinė programa
└── test.cpp              # Testų rinkinys
```

## Projekto Surinkimas
Projektas naudoja CMake surinkimui. Surinkimui:
```bash
mkdir build
cd build
cmake ..
make
```

## Testavimas
- Projektas turi testų rinkinį `test.cpp` faile
- Konkretus `notification_test` bus įgyvendintas po Pranešimų Sistemos užbaigimo
- Testus paleiskite naudodami surinktą testų vykdomąjį failą

## Projektavimo Šablonai
Sistema naudoja Observer pattern, kad išlaikytų laisvą ryšį tarp narystės sistemos ir jos įvairių posistemių. Tai leidžia:
- Lengvai pridėti naujus posistemius
- Atskirti komponentų komunikaciją
- Efektyviai atnaujinti duomenis, kai keičiasi narystės informacija