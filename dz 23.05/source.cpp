#include <iostream>
#include <string>
using namespace std;

class Device {
public:
    virtual ~Device() = default;
    virtual string getName() const = 0;
    virtual string getSpecs() const = 0;
};

class VideoCard : public Device {
public:
    string getName() const override {
        return "Video Card";
    }

    string getSpecs() const override {
        return "Radeon RX 6600 V2 8192MB";
    }
};

class Processor : public Device {
public:
    string getName() const override {
        return "Processor";
    }

    string getSpecs() const override {
        return "Intel Core i5-12400F, 2.5GHz, 6 cores";
    }
};

class Motherboard : public Device {
public:
    string getName() const override {
        return "Motherboard";
    }

    string getSpecs() const override {
        return "MSI PRO B760-P WIFI DDR4";
    }
};

class HardDisk : public Device {
public:
    string getName() const override {
        return "Hard Disk";
    }

    string getSpecs() const override {
        return "Toshiba P300 1TB";
    }
};

class RAM : public Device {
public:
    string getName() const override {
        return "RAM";
    }

    string getSpecs() const override {
        return "Kingston DDR4 16GB (2x8GB) 3200Mhz";
    }
};

class PowerSupply : public Device {
public:
    string getName() const override {
        return "PowerSupply";
    }

    string getSpecs() const override {
        return "MSI MAG 750W PCIE5";
    }
};


class Report {
protected:
    Device* device;

public:
    explicit Report(Device* dev) : device(dev) {}
    virtual ~Report() = default;

    virtual void printReport() const = 0;
};


class SimpleReport : public Report {
public:
    using Report::Report;

    void printReport() const override {
        cout << "<----------------------------->" << endl;
        cout << "Device: " << device->getName() << endl;
        cout << "Characteristic: " << device->getSpecs() << endl;
      
    }
};

int main() {

    cout << "Final computer assembly: " << endl;

    Device* videoCard = new VideoCard();
    Device* processor = new Processor();
    Device* motherboard = new Motherboard();
    Device* hardDisk = new HardDisk();
    Device* ram = new RAM();
    Device* powersupply = new PowerSupply();

    Report* report1 = new SimpleReport(videoCard);
    Report* report2 = new SimpleReport(processor);
    Report* report3 = new SimpleReport(hardDisk);
    Report* report4 = new SimpleReport(ram);
    Report* report5 = new SimpleReport(motherboard);
    Report* report6 = new SimpleReport(powersupply);

    report1->printReport();
    report2->printReport();
    report3->printReport();
    report4->printReport();
    report5->printReport();
    report6->printReport();

    delete report1;
    delete report2;
    delete report3;
    delete report4;
    delete report5;
    delete report6;
    delete videoCard;
    delete processor;
    delete hardDisk;
    delete ram;
    delete motherboard;
    delete powersupply;

    return 0;
}
