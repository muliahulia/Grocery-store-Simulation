#ifndef DATA_H
#define DATA_H

class Data {
public:
    Data() {}
    Data(int customerNumber, int serviceTime);
    ~Data();

    int getCustomerNumber() const;
    int getServiceTime() const;
    int getTotalTime() const;

    void decrementServiceTime() {
        if (serviceTime > 0) {
            serviceTime--;
        }
    }

    void setTotalTime(int totalTime);
   

private:
    int customerNumber;
    int serviceTime;
    int totalTime;
};

#endif // DATA_H
