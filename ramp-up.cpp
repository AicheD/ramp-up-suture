#include <iostream>
#include <cstdlib>  // has rand() and srand()
#include <ctime>    // has time()

float pressureThreshold = 75.0;  // arbitrary value for pressure

// simulate pressure data
float readPressure() {
    // fake data 0-100
    return rand() % 101;
}

void setup() {
    srand(time(0));
    std::cout << "Pressure Sensor Simulation Started\n";
}

void loop() {
    float pressure = readPressure();  // sim reading current pressure

    // display pressure
    std::cout << "Current Pressure: " << pressure << std::endl;

    // check if pressure exceeds threshold --- alert user if over
    if (pressure > pressureThreshold) {
        std::cout << "ALERT: Pressure Exceeded!" << std::endl;
    }

    // wait before reading again (simulated with sleep)
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main() {
    // made it like arduino
    setup();

    while (true) {
        loop();  // forever and ever
    }

    return 0;
}
