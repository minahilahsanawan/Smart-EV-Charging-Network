#include <iostream>             // This header is used for input and output.
#include <vector>                // This header is used for dynamic lists.
#include <string>                 // This header is used for text handling.
#include <memory>                  // This header is used for smart pointers.
#include <fstream>                   // This header is used for file saving.
#include <iomanip>                    // This header is used for neat decimal formatting.
#include <algorithm>                  // This header is used for min and max.
#include <cctype>                     // This header is used for character conversion.
using namespace std;                 // This lets us use standard library names directly.
string trim(string text){           // This function removes spaces from the start and end of a string.
    if(text==""){                  // This checks if the string is already empty.
        return "";                // This returns an empty string immediately.
    }
    int start=0;               // This stores the first useful character position.
    while(start<(int)text.size()&&text[start]==' '){           // This skips spaces from the start.
        start++;                    // This moves the start position forward.
    }
    if(start==(int)text.size()){         // This checks if the whole string was only spaces.
        return "";                      // This returns an empty string.
    }
    int end=(int)text.size()-1;                  // This stores the last useful character position.
    while(end>=start&&text[end]==' '){           // This skips spaces from the end.
        end--;                                  // This moves the end position backward.
    }
    return text.substr(start,end-start+1);          // This returns the cleaned part.
}
string toLowerCase(string text){               // This function converts all letters to lower case.
    for(int i=0;i<(int)text.size();i++){          // This loop visits each character.
        text[i]=(char)tolower((unsigned char)text[i]);    // This converts one character safely.
    }
    return text;            // This returns the lower-case string.
}
string capitalizeWord(string text){      // This function makes the first letter capital and the rest lower case.
    text=trim(text);                    // This removes extra spaces first.
    if(text==""){            // This checks if the string is empty.
        return "";         // This returns empty text.
    }
    text=toLowerCase(text);                             // This makes the whole word lower case.
    text[0]=(char)toupper((unsigned char)text[0]);          // This capitalizes the first letter.
    return text;                                           // This returns the cleaned word.
}
string normalizeMembership(string text){       // This function standardizes membership text.
    text=toLowerCase(trim(text));              // This prepares the text for comparison.
    if(text=="regular"){                       // This checks regular membership.
        return "Regular";                   // This returns the standard value.
    }
    if(text=="premium"){            // This checks premium membership.
        return "Premium";             // This returns the standard value.
    }
    if(text=="vip"){                // This checks VIP membership.
        return "VIP";                // This returns the standard value.
    }
    return "";                        // This returns empty if the value is invalid.
}
string normalizeConnector(string text){          // This function standardizes connector text.
    text=toLowerCase(trim(text));              // This prepares the text for comparison.
    if(text=="type2"||text=="type 2"){          // This checks Type2.
        return "Type2";                        // This returns the standard value.
    }
    if(text=="ccs"){                     // This checks CCS.
        return "CCS";                   // This returns the standard value.
    }
    if(text=="chademo"||text=="cha demo"){              // This checks CHAdeMO.
        return "CHAdeMO";                             // This returns the standard value.
    }
    return "";                         // This returns empty if the value is invalid.
}
string normalizeDockType(string text){            // This function standardizes dock type text.
    text=toLowerCase(trim(text));             // This prepares the text for comparison.
    if(text=="slow"){                       // This checks Slow.
        return "Slow";                     // This returns the standard value.
    }
    if(text=="medium"){                // This checks Medium.
        return "Medium";              // This returns the standard value.
    } 
    if(text=="fast"){                // This checks Fast.
        return "Fast";             // This returns the standard value.
    }
    return "";                  // This returns empty if the value is invalid.
}
class InputHelper{            // This class groups safe input helper functions.
public:
    static string readLine(string prompt){         // This function reads one non-empty line.
        string value;             // This stores user input.
        while(true){                   // This loop repeats until valid input is entered.
            cout<<prompt;              // This prints the prompt.
            getline(cin,value);        // This reads the full line.
            value=trim(value);       // This removes extra spaces.
            if(value!=""){           // This checks whether text is not empty.
                return value;         // This returns valid text.
            }
            cout<<"Invalid input. Please enter something!\n"; // This prints an error.
        }
    }
    static int readInt(string prompt,int minimum,int maximum){ // This function reads an integer in a valid range.
        int value; // This stores the number.
        while(true){ // This loop repeats until valid input is entered.
            cout<<prompt; // This prints the prompt.
            cin>>value; // This tries to read an integer.
            if(cin.fail()){ // This checks whether input was not numeric.
                cin.clear(); // This clears the error state.
                cin.ignore(1000,'\n'); // This removes bad input from the buffer.
                cout<<"Invalid input. Please enter an integer!\n"; // This prints an error.
            }else if(value<minimum||value>maximum){ // This checks range.
                cin.ignore(1000,'\n'); // This clears the newline.
                cout<<"Invalid input. Enter a value between "<<minimum<<" and "<<maximum<<"!\n"; // This prints an error.
            }else{ // This runs when input is valid.
                cin.ignore(1000,'\n'); // This clears the newline.
                return value; // This returns the valid integer.
            }
        }
    }
    static double readDouble(string prompt,double minimum,double maximum){ // This function reads a decimal number in a valid range.
        double value; // This stores the number.
        while(true){ // This loop repeats until valid input is entered.
            cout<<prompt; // This prints the prompt.
            cin>>value; // This tries to read a decimal number.
            if(cin.fail()){ // This checks whether input was not numeric.
                cin.clear(); // This clears the error state.
                cin.ignore(1000,'\n'); // This removes bad input from the buffer.
                cout<<"Invalid input. Please enter a number!\n"; // This prints an error.
            }else if(value<minimum||value>maximum){ // This checks range.
                cin.ignore(1000,'\n'); // This clears the newline.
                cout<<"Invalid input. Enter a value between "<<minimum<<" and "<<maximum<<"!\n"; // This prints an error.
            }else{ // This runs when input is valid.
                cin.ignore(1000,'\n'); // This clears the newline.
                return value; // This returns the valid number.
            }
        }
    }
    static string readMembership(string prompt){ // This function reads a valid membership value.
        while(true){ // This loop repeats until valid input is entered.
            string value=normalizeMembership(readLine(prompt)); // This reads and normalizes the text.
            if(value!=""){ // This checks whether the membership is valid.
                return value; // This returns the valid membership.
            }
            cout<<"Invalid membership. Enter Regular, Premium, or VIP!\n"; // This prints an error.
        }
    }
    static string readConnector(string prompt){ // This function reads a valid connector value.
        while(true){ // This loop repeats until valid input is entered.
            string value=normalizeConnector(readLine(prompt)); // This reads and normalizes the text.
            if(value!=""){ // This checks whether the connector is valid.
                return value; // This returns the valid connector.
            }
            cout<<"Invalid connector. Enter Type2, CCS, or CHAdeMO!\n"; // This prints an error.
        }
    }
    static string readDockType(string prompt){ // This function reads a valid dock type.
        while(true){ // This loop repeats until valid input is entered.
            string value=normalizeDockType(readLine(prompt)); // This reads and normalizes the text.
            if(value!=""){ // This checks whether the dock type is valid.
                return value; // This returns the valid dock type.
            }
            cout<<"Invalid dock type. Enter Slow, Medium, or Fast!\n"; // This prints an error.
        }
    }
    static bool readYesNo(string prompt){ // This function reads yes or no.
        while(true){ // This loop repeats until valid input is entered.
            string value=toLowerCase(readLine(prompt)); // This reads and normalizes the text.
            if(value=="yes"||value=="y"){ // This checks yes.
                return true; // This returns true for yes.
            }
            if(value=="no"||value=="n"){ // This checks no.
                return false; // This returns false for no.
            }
            cout<<"Invalid input. Please enter yes or no!\n"; // This prints an error.
        }
    }
};
class EV{ // This class stores one electric vehicle.
private:
    int id; // This stores EV id.
    string model; // This stores EV model.
    string vehicleType; // This stores EV type.
    double batteryCapacity; // This stores battery capacity in kWh.
    double currentSOC; // This stores current state of charge in percent.
    double maxChargeRate; // This stores maximum charging rate.
    string connectorType; // This stores connector type.
    bool v2gEnabled; // This future-ready field shows whether the EV supports V2G.
    double availableDischargeEnergy; // This future-ready field stores placeholder discharge energy.
public:
    EV(){} // This is an empty constructor.
    EV(int a,string b,string c,double d,double e,double f,string g,bool h=false){ // This constructor sets EV data.
        id=a; // This sets EV id.
        model=b; // This sets model.
        vehicleType=c; // This sets type.
        batteryCapacity=d; // This sets battery capacity.
        currentSOC=e; // This sets SOC.
        maxChargeRate=f; // This sets max charging rate.
        connectorType=g; // This sets connector type.
        v2gEnabled=h; // This sets V2G support.
        availableDischargeEnergy=batteryCapacity*0.10; // This reserves a simple placeholder amount for future V2G support.
    }
    int getId() const{ // This function returns EV id.
        return id; // This returns the stored id.
    }
    string getModel() const{ // This function returns EV model.
        return model; // This returns the stored model.
    }
    string getVehicleType() const{ // This function returns EV type.
        return vehicleType; // This returns the stored type.
    }
    double getBatteryCapacity() const{ // This function returns battery capacity.
        return batteryCapacity; // This returns the stored capacity.
    }
    double getCurrentSOC() const{ // This function returns current SOC.
        return currentSOC; // This returns the stored SOC.
    }
    double getMaxChargeRate() const{ // This function returns max charging rate.
        return maxChargeRate; // This returns the stored rate.
    }
    string getConnectorType() const{ // This function returns connector type.
        return connectorType; // This returns the stored connector.
    }
    bool isV2GEnabled() const{ // This function returns V2G support status.
        return v2gEnabled; // This returns the stored V2G flag.
    }
    double getNeededEnergy() const{ // This function calculates energy needed to reach full charge.
        return batteryCapacity*(100.0-currentSOC)/100.0; // This returns the needed energy in kWh.
    }
    void updateSOC(double deliveredEnergy){ // This function updates SOC after charging.
        double addedPercent=(deliveredEnergy/batteryCapacity)*100.0; // This converts delivered energy into battery percentage.
        currentSOC=currentSOC+addedPercent; // This adds the new charge.
        if(currentSOC>100.0){ // This checks if SOC became more than 100.
            currentSOC=100.0; // This keeps SOC at 100 maximum.
        }
    }
    void dischargeToGrid(double amount){ // This is a future-ready placeholder method for V2G support.
        if(v2gEnabled&&amount>0&&availableDischargeEnergy>=amount){ // This checks a simple future-ready discharge condition.
            availableDischargeEnergy=availableDischargeEnergy-amount; // This reduces discharge energy in a future V2G scenario.
        }
    }
};
class User{ // This class stores one system user.
private:
    int id; // This stores user id.
    string name; // This stores user name.
    string membershipLevel; // This stores membership level.
    int priorityLevel; // This stores user priority.
    vector<int> vehicleIds; // This stores ids of this user's EVs.
    vector<string> notifications; // This stores the user's notifications.
public:
    User(){} // This is an empty constructor.
    User(int a,string b,string c,int d){ // This constructor sets user data.
        id=a; // This sets id.
        name=b; // This sets name.
        membershipLevel=c; // This sets membership.
        priorityLevel=d; // This sets priority.
    }
    int getId() const{ // This function returns user id.
        return id; // This returns stored id.
    }
    string getName() const{ // This function returns user name.
        return name; // This returns stored name.
    }
    string getMembershipLevel() const{ // This function returns membership level.
        return membershipLevel; // This returns stored membership.
    }
    int getPriorityLevel() const{ // This function returns priority level.
        return priorityLevel; // This returns stored priority.
    }
    void addVehicle(int vehicleId){ // This function links one EV with the user.
        vehicleIds.push_back(vehicleId); // This saves the EV id.
    }
    bool ownsVehicle(int vehicleId) const{ // This function checks whether the user owns a given EV.
        for(int i=0;i<(int)vehicleIds.size();i++){ // This loop checks all EV ids of the user.
            if(vehicleIds[i]==vehicleId){ // This checks match.
                return true; // This means the EV belongs to the user.
            }
        }
        return false; // This means the EV does not belong to the user.
    }
    const vector<int>& getVehicleIds() const{ // This function returns the user's EV list safely.
        return vehicleIds; // This returns the EV ids.
    }
    void addNotification(string message){ // This function adds one user notification.
        notifications.push_back(message); // This saves the message.
    }
    void showNotifications() const{ // This function prints all notifications.
        cout<<"\nNotifications for "<<name<<":\n"; // This prints the heading.
        if(notifications.size()==0){ // This checks if there are no notifications.
            cout<<"No notifications available.\n"; // This prints a helpful message.
            return; // This stops the function.
        }
        for(int i=0;i<(int)notifications.size();i++){ // This loop prints every notification.
            cout<<i+1<<". "<<notifications[i]<<"\n"; // This prints one notification.
        }
    }
};
class EnergySource{ // This class stores common data for all energy sources.
protected:
    string name; // This stores source name.
    double availableEnergy; // This stores available energy in kWh.
    double costPerKWh; // This stores cost per kWh.
    double emissionFactor; // This stores emission factor.
public:
    EnergySource(){} // This is an empty constructor.
    EnergySource(string a,double b,double c,double d){ // This constructor sets source data.
        name=a; // This sets name.
        availableEnergy=b; // This sets available energy.
        costPerKWh=c; // This sets cost.
        emissionFactor=d; // This sets emission factor.
    }
    virtual string getType() const{ // This function returns source type.
        return name; // This returns the stored name.
    }
    virtual bool isRenewable() const{ // This function tells whether the source is renewable.
        return false; // The base type is treated as non-renewable by default.
    }
    double getAvailableEnergy() const{ // This function returns available energy.
        return availableEnergy; // This returns the stored value.
    }
    double getCostPerKWh() const{ // This function returns cost per kWh.
        return costPerKWh; // This returns the stored value.
    }
    void consumeEnergy(double amount){ // This function reduces available energy.
        availableEnergy=availableEnergy-amount; // This subtracts the used energy.
        if(availableEnergy<0){ // This checks if energy became negative.
            availableEnergy=0; // This keeps it at zero minimum.
        }
    }
};
class GridPower:public EnergySource{ // This class stores grid energy.
public:
    GridPower(){} // This is an empty constructor.
    GridPower(double energy,double cost,double emission){ // This constructor sets grid values.
        name="GridPower"; // This sets source name.
        availableEnergy=energy; // This sets available energy.
        costPerKWh=cost; // This sets cost.
        emissionFactor=emission; // This sets emission.
    }
    string getType() const override{ // This function returns source type.
        return "GridPower"; // This returns the grid label.
    }
    bool isRenewable() const override{ // This function tells if source is renewable.
        return false; // Grid is not renewable.
    }
};
class SolarPower:public EnergySource{ // This class stores solar energy.
public:
    SolarPower(){} // This is an empty constructor.
    SolarPower(double energy,double cost,double emission){ // This constructor sets solar values.
        name="SolarPower"; // This sets source name.
        availableEnergy=energy; // This sets available energy.
        costPerKWh=cost; // This sets cost.
        emissionFactor=emission; // This sets emission.
    }
    string getType() const override{ // This function returns source type.
        return "SolarPower"; // This returns the solar label.
    }
    bool isRenewable() const override{ // This function tells if source is renewable.
        return true; // Solar is renewable.
    }
};
class WindPower:public EnergySource{ // This class stores wind energy.
public:
    WindPower(){} // This is an empty constructor.
    WindPower(double energy,double cost,double emission){ // This constructor sets wind values.
        name="WindPower"; // This sets source name.
        availableEnergy=energy; // This sets available energy.
        costPerKWh=cost; // This sets cost.
        emissionFactor=emission; // This sets emission.
    }
    string getType() const override{ // This function returns source type.
        return "WindPower"; // This returns the wind label.
    }
    bool isRenewable() const override{ // This function tells if source is renewable.
        return true; // Wind is renewable.
    }
};
class ChargingDock{ // This class stores one charging dock.
private:
    int id; // This stores dock id.
    string dockType; // This stores dock type.
    double powerRating; // This stores dock power rating.
    string connectorType; // This stores connector type.
    string status; // This stores dock status.
    int currentEVId; // This stores the EV currently using the dock.
public:
    ChargingDock(){} // This is an empty constructor.
    ChargingDock(int a,string b,double c,string d){ // This constructor sets dock data.
        id=a; // This sets dock id.
        dockType=b; // This sets dock type.
        powerRating=c; // This sets power rating.
        connectorType=d; // This sets connector type.
        status="Available"; // This sets the starting status.
        currentEVId=-1; // This means no EV is using the dock yet.
    }
    int getId() const{ // This function returns dock id.
        return id; // This returns stored id.
    }
    string getDockType() const{ // This function returns dock type.
        return dockType; // This returns stored type.
    }
    double getPowerRating() const{ // This function returns dock power rating.
        return powerRating; // This returns stored power.
    }
    string getConnectorType() const{ // This function returns connector type.
        return connectorType; // This returns stored connector.
    }
    string getStatus() const{ // This function returns dock status.
        return status; // This returns stored status.
    }
    bool isAvailable() const{ // This function checks whether the dock is free.
        return status=="Available"; // This returns true if the dock is free.
    }
    void assignEV(int evId){ // This function reserves the dock for an EV.
        currentEVId=evId; // This stores EV id.
        status="Occupied"; // This marks the dock as busy.
    }
    void releaseDock(){ // This function frees the dock.
        currentEVId=-1; // This removes EV id.
        status="Available"; // This marks the dock as free again.
    }
};
class Booking{ // This class stores one booking.
private:
    int id; // This stores booking id.
    int userId; // This stores user id.
    int evId; // This stores EV id.
    int stationId; // This stores station id.
    int dockId; // This stores dock id.
    int requestedStartHour; // This stores requested start hour.
    int durationHours; // This stores session duration.
    int userPriority; // This stores user priority.
    double requestedEnergy; // This stores requested energy.
    double assignedPower; // This stores assigned power.
    string energySourceType; // This stores selected source type.
    double sourceCostPerKWh; // This stores source cost.
    string status; // This stores booking status.
    double cancellationPenalty; // This stores cancellation penalty.
public:
    Booking(){} // This is an empty constructor.
    Booking(int a,int b,int c,int d,int e,int f,int g,double h){ // This constructor sets booking data.
        id=a; // This sets booking id.
        userId=b; // This sets user id.
        evId=c; // This sets EV id.
        stationId=d; // This sets station id.
        dockId=-1; // This starts with no dock.
        requestedStartHour=e; // This sets requested start hour.
        durationHours=f; // This sets duration.
        userPriority=g; // This sets priority.
        requestedEnergy=h; // This sets requested energy.
        assignedPower=0; // This starts with no assigned power.
        energySourceType="NotSelected"; // This starts with no energy source.
        sourceCostPerKWh=0; // This starts with no source cost.
        status="Pending"; // This starts with pending status.
        cancellationPenalty=0; // This starts with no penalty.
    }
    int getId() const{ // This function returns booking id.
        return id; // This returns stored id.
    }
    int getUserId() const{ // This function returns user id.
        return userId; // This returns stored user id.
    }
    int getEVId() const{ // This function returns EV id.
        return evId; // This returns stored EV id.
    }
    int getStationId() const{ // This function returns station id.
        return stationId; // This returns stored station id.
    }
    int getDockId() const{ // This function returns dock id.
        return dockId; // This returns stored dock id.
    }
    int getRequestedStartHour() const{ // This function returns requested start hour.
        return requestedStartHour; // This returns stored start hour.
    }
    int getDurationHours() const{ // This function returns session duration.
        return durationHours; // This returns stored duration.
    }
    int getUserPriority() const{ // This function returns priority.
        return userPriority; // This returns stored priority.
    }
    double getRequestedEnergy() const{ // This function returns requested energy.
        return requestedEnergy; // This returns stored energy.
    }
    double getAssignedPower() const{ // This function returns assigned power.
        return assignedPower; // This returns stored power.
    }
    string getEnergySourceType() const{ // This function returns source type.
        return energySourceType; // This returns stored source type.
    }
    double getSourceCostPerKWh() const{ // This function returns source cost.
        return sourceCostPerKWh; // This returns stored source cost.
    }
    string getStatus() const{ // This function returns booking status.
        return status; // This returns stored status.
    }
    double getCancellationPenalty() const{ // This function returns cancellation penalty.
        return cancellationPenalty; // This returns stored penalty.
    }
    void setDockAndPower(int newDockId,double newPower){ // This function sets assigned dock and power in a controlled way.
        dockId=newDockId; // This stores dock id.
        assignedPower=newPower; // This stores power.
    }
    void setEnergySource(string sourceType,double sourceCost){ // This function sets source details in a controlled way.
        energySourceType=sourceType; // This stores source type.
        sourceCostPerKWh=sourceCost; // This stores source cost.
    }
    void setRequestedStartHour(int hour){ // This function updates requested hour in a controlled way.
        requestedStartHour=hour; // This stores new hour.
    }
    void markDeferred(){ // This function marks the booking as deferred.
        status="Deferred"; // This stores deferred status.
    }
    void markActive(){ // This function marks the booking as active.
        status="Active"; // This stores active status.
    }
    void markCompleted(){ // This function marks the booking as completed.
        status="Completed"; // This stores completed status.
    }
    void markCancelled(double penalty){ // This function marks the booking as cancelled and stores penalty.
        status="Cancelled"; // This stores cancelled status.
        cancellationPenalty=penalty; // This stores penalty.
    }
};
class Invoice{ // This class stores invoice details.
private:
    int id; // This stores invoice id.
    int bookingId; // This stores booking id.
    double energyConsumed; // This stores consumed energy.
    double sessionDuration; // This stores session duration.
    string energySourceType; // This stores source type.
    double ratePerKWh; // This stores final rate.
    double totalAmount; // This stores total bill.
    double timeFactor; // This stores time factor.
    double speedFactor; // This stores speed factor.
    double sourceFactor; // This stores source factor.
    double membershipFactor; // This stores membership factor.
public:
    Invoice(){} // This is an empty constructor.
    Invoice(int a,int b,double c,double d,string e,double f,double g,double h,double i,double j,double k){ // This constructor sets invoice data.
        id=a; // This sets invoice id.
        bookingId=b; // This sets booking id.
        energyConsumed=c; // This sets energy consumed.
        sessionDuration=d; // This sets duration.
        energySourceType=e; // This sets source type.
        ratePerKWh=f; // This sets rate.
        totalAmount=g; // This sets total amount.
        timeFactor=h; // This sets time factor.
        speedFactor=i; // This sets speed factor.
        sourceFactor=j; // This sets source factor.
        membershipFactor=k; // This sets membership factor.
    }
    void printInvoice() const{ // This function prints the invoice.
        cout<<"\n=========== DIGITAL INVOICE ===========\n"; // This prints heading.
        cout<<fixed<<setprecision(2); // This formats decimal values.
        cout<<"Invoice ID: "<<id<<"\n"; // This prints invoice id.
        cout<<"Booking ID: "<<bookingId<<"\n"; // This prints booking id.
        cout<<"Energy Consumed: "<<energyConsumed<<" kWh\n"; // This prints energy consumed.
        cout<<"Session Duration: "<<sessionDuration<<" hours\n"; // This prints duration.
        cout<<"Energy Source: "<<energySourceType<<"\n"; // This prints source.
        cout<<"Rate Per kWh: "<<ratePerKWh<<"\n"; // This prints rate.
        cout<<"Time Factor: "<<timeFactor<<"\n"; // This prints time factor.
        cout<<"Speed Factor: "<<speedFactor<<"\n"; // This prints speed factor.
        cout<<"Source Factor: "<<sourceFactor<<"\n"; // This prints source factor.
        cout<<"Membership Factor: "<<membershipFactor<<"\n"; // This prints membership factor.
        cout<<"Total Amount: "<<totalAmount<<"\n"; // This prints total amount.
    }
    void saveToFile() const{ // This function saves the invoice in a text file.
        ofstream outFile("invoices.txt",ios::app); // This opens the invoice file in append mode so old data stays safe.
        if(!outFile){ // This checks whether the file opened correctly.
            cout<<"Warning: invoice file could not be opened!!\n"; // This prints a warning.
            return; // This stops the function.
        }
        outFile<<fixed<<setprecision(2); // This formats decimals in the file.
        outFile<<"=========== DIGITAL INVOICE ===========\n"; // This writes heading.
        outFile<<"Invoice ID: "<<id<<"\n"; // This writes invoice id.
        outFile<<"Booking ID: "<<bookingId<<"\n"; // This writes booking id.
        outFile<<"Energy Consumed: "<<energyConsumed<<" kWh\n"; // This writes energy.
        outFile<<"Session Duration: "<<sessionDuration<<" hours\n"; // This writes duration.
        outFile<<"Energy Source: "<<energySourceType<<"\n"; // This writes source.
        outFile<<"Rate Per kWh: "<<ratePerKWh<<"\n"; // This writes rate.
        outFile<<"Time Factor: "<<timeFactor<<"\n"; // This writes time factor.
        outFile<<"Speed Factor: "<<speedFactor<<"\n"; // This writes speed factor.
        outFile<<"Source Factor: "<<sourceFactor<<"\n"; // This writes source factor.
        outFile<<"Membership Factor: "<<membershipFactor<<"\n"; // This writes membership factor.
        outFile<<"Total Amount: "<<totalAmount<<"\n"; // This writes total amount.
    }
};
class ChargingStation{ // This class stores one charging station.
private:
    int id; // This stores station id.
    string name; // This stores station name.
    string location; // This stores station location.
    double gridCapacity; // This stores maximum safe active load.
    double currentLoad; // This stores current active load.
    vector<ChargingDock> docks; // This stores all docks of the station.
    vector<shared_ptr<EnergySource>> energySources; // This stores all energy sources of the station.
public:
    ChargingStation(){} // This is an empty constructor.
    ChargingStation(int a,string b,string c,double d){ // This constructor sets station data.
        id=a; // This sets station id.
        name=b; // This sets station name.
        location=c; // This sets station location.
        gridCapacity=d; // This sets station capacity.
        currentLoad=0; // This starts with zero active load.
    }
    int getId() const{ // This function returns station id.
        return id; // This returns stored id.
    }
    string getName() const{ // This function returns station name.
        return name; // This returns stored name.
    }
    double getCurrentLoad() const{ // This function returns current load.
        return currentLoad; // This returns current load.
    }
    const vector<ChargingDock>& getDocks() const{ // This function returns station docks safely.
        return docks; // This returns docks.
    }
    vector<ChargingDock>& accessDocks(){ // This function gives controlled non-const access to docks for internal network operations.
        return docks; // This returns docks.
    }
    const vector<shared_ptr<EnergySource>>& getEnergySources() const{ // This function returns energy sources safely.
        return energySources; // This returns energy sources.
    }
    vector<shared_ptr<EnergySource>>& accessEnergySources(){ // This function gives controlled non-const access to sources for internal network operations.
        return energySources; // This returns energy sources.
    }
    void addDock(ChargingDock dock){ // This function adds one dock to the station.
        docks.push_back(dock); // This stores the dock.
    }
    void addEnergySource(shared_ptr<EnergySource> source){ // This function adds one energy source to the station.
        energySources.push_back(source); // This stores the energy source.
    }
    void updateRenewableForecast(){ // This is a future-ready placeholder for external API integration.
        // Future extension: weather or other external APIs can update solar and wind forecast here.
    }
    void fetchExternalStationData(){ // This is a future-ready placeholder for general external APIs.
        // Future extension: payment, smart-grid, mapping, or forecast APIs can be connected here.
    }
    int getTotalDocks() const{ // This function returns total dock count.
        return (int)docks.size(); // This returns the number of docks.
    }
    int getOccupiedDocks() const{ // This function returns occupied dock count.
        int count=0; // This stores occupied count.
        for(int i=0;i<(int)docks.size();i++){ // This loop checks every dock.
            if(docks[i].getStatus()=="Occupied"){ // This checks if the dock is busy.
                count++; // This increases the count.
            }
        }
        return count; // This returns the final count.
    }
    bool isPeakHour(int hour) const{ // This function checks whether the given hour belongs to peak time.
        if((hour>=8&&hour<=10)||(hour>=17&&hour<=21)){ // This checks morning peak OR evening peak using correct ranges.
            return true; // This means it is peak hour.
        }
        return false; // This means it is not peak hour.
    }
    bool canAcceptLoad(double extraLoad) const{ // This function checks whether the station can safely handle more load.
        return currentLoad+extraLoad<=gridCapacity; // This returns true only if the new load stays within capacity.
    }
    void addLoad(double load){ // This function adds load to the station in a controlled way.
        currentLoad=currentLoad+load; // This increases current load.
    }
    void removeLoad(double load){ // This function removes load from the station in a controlled way.
        currentLoad=currentLoad-load; // This reduces current load.
        if(currentLoad<0){ // This checks negative load.
            currentLoad=0; // This keeps it safe at zero.
        }
    }
    int findBestDockIndex(const EV& ev,int userPriority) const{ // This function finds the best available compatible dock.
        int bestIndex=-1; // This stores the best dock index.
        double bestScore=999999; // This starts with a very large score.
        double desiredPower=7; // This starts with slow charging as default.
        if(userPriority>=3||ev.getCurrentSOC()<=30){ // This checks urgent cases.
            desiredPower=min(ev.getMaxChargeRate(),50.0); // This prefers fast charging.
        }else if(ev.getCurrentSOC()<=60){ // This checks medium urgency.
            desiredPower=min(ev.getMaxChargeRate(),22.0); // This prefers medium charging.
        }else{ // This handles low urgency.
            desiredPower=min(ev.getMaxChargeRate(),7.0); // This prefers slow charging.
        }
        for(int i=0;i<(int)docks.size();i++){ // This loop checks every dock.
            if(!docks[i].isAvailable()){ // This skips occupied docks.
                continue; // This moves to the next dock.
            }
            if(docks[i].getConnectorType()!=ev.getConnectorType()){ // This skips incompatible connectors.
                continue; // This moves to the next dock.
            }
            double difference=docks[i].getPowerRating()-desiredPower; // This finds the difference between actual and desired power.
            if(difference<0){ // This checks if the difference is negative.
                difference=difference*-1; // This makes it positive.
            }
            double extraPenalty=0; // This stores an extra penalty.
            if(userPriority<=1&&ev.getCurrentSOC()>70&&docks[i].getPowerRating()>22){ // This checks a low-priority wasteful case.
                extraPenalty=20; // This discourages using a very fast dock unnecessarily.
            }
            double vehiclePenalty=0; // This stores a vehicle-type-based penalty.
            string type=ev.getVehicleType(); // This gets the EV type.
            if(type=="Bike"&&docks[i].getPowerRating()>22){ // This discourages high-power docks for bikes.
                vehiclePenalty=15;
            }else if(type=="Van"&&docks[i].getPowerRating()<22){ // This discourages very slow docks for vans.
                vehiclePenalty=10;
            }else if(type=="Bus"&&docks[i].getPowerRating()<50){ // This strongly prefers fast docks for buses.
                vehiclePenalty=25;
            }
            double score=difference+extraPenalty+vehiclePenalty; // This builds the final score.
            if(score<bestScore){ // This checks whether the current dock is better.
                bestScore=score; // This stores the better score.
                bestIndex=i; // This stores the better dock index.
            }
        }
        return bestIndex; // This returns the best dock index or -1.
    }
    int findSafeLowPowerDockIndex(const EV& ev) const{ // This function supports a simple load-shedding policy by finding a compatible lower-power safe dock.
        int bestIndex=-1; // This stores the best safe dock index.
        double smallestPower=999999; // This starts with a very large power value.
        for(int i=0;i<(int)docks.size();i++){ // This loop checks every dock.
            if(!docks[i].isAvailable()){ // This skips occupied docks.
                continue; // This moves to the next dock.
            }
            if(docks[i].getConnectorType()!=ev.getConnectorType()){ // This skips incompatible connectors.
                continue; // This moves to the next dock.
            }
            if(!canAcceptLoad(docks[i].getPowerRating())){ // This skips docks that still overload the station.
                continue; // This moves to the next dock.
            }
            if(ev.getVehicleType()=="Bus"&&docks[i].getPowerRating()<50){ // This avoids assigning too-low power docks to buses.
                continue; // This moves to the next dock.
            }
            if(ev.getVehicleType()=="Van"&&docks[i].getPowerRating()<22){ // This avoids assigning very slow docks to vans.
                continue; // This moves to the next dock.
            }
            if(docks[i].getPowerRating()<smallestPower){ // This checks if this dock uses the smallest safe power.
                smallestPower=docks[i].getPowerRating(); // This stores the smaller power.
                bestIndex=i; // This stores that dock index.
            }
        }
        return bestIndex; // This returns a safer dock index or -1.
    }
    shared_ptr<EnergySource> chooseEnergySource(double requiredEnergy,bool preferRenewable){ // This function selects a suitable energy source.
        if(preferRenewable){ // This checks whether renewable should be preferred first.
            for(int i=0;i<(int)energySources.size();i++){ // This loop checks all sources.
                if(energySources[i]->isRenewable()&&energySources[i]->getAvailableEnergy()>=requiredEnergy){ // This looks for a renewable source with enough energy.
                    return energySources[i]; // This returns that source.
                }
            }
        }
        for(int i=0;i<(int)energySources.size();i++){ // This loop checks all sources again.
            if(energySources[i]->getAvailableEnergy()>=requiredEnergy){ // This checks any source with enough energy.
                return energySources[i]; // This returns that source.
            }
        }
        for(int i=0;i<(int)energySources.size();i++){ // This loop checks all sources one more time.
            if(energySources[i]->getAvailableEnergy()>0){ // This checks any partially available source.
                return energySources[i]; // This returns that source.
            }
        }
        return nullptr; // This means no source was available.
    }
    void showStationInfo() const{ // This function prints station details.
        cout<<"\nStation ID: "<<id<<"\n"; // This prints id.
        cout<<"Name: "<<name<<"\n"; // This prints name.
        cout<<"Location: "<<location<<"\n"; // This prints location.
        cout<<"Grid Capacity (kW): "<<gridCapacity<<"\n"; // This prints grid capacity.
        cout<<"Current Active Load (kW): "<<currentLoad<<"\n"; // This prints current load.
        cout<<"Dock Details:\n"; // This prints the dock heading.
        if(docks.size()==0){ // This checks if there are no docks.
            cout<<"No docks added yet.\n"; // This prints a helpful message.
        }else{ // This block prints dock details.
            for(int i=0;i<(int)docks.size();i++){ // This loop prints every dock.
                cout<<"Dock "<<docks[i].getId()<<" | Type: "<<docks[i].getDockType()<<" | Power: "<<docks[i].getPowerRating()<<"kW | Connector: "<<docks[i].getConnectorType()<<" | Status: "<<docks[i].getStatus()<<"\n"; // This prints one dock line.
            }
        }
        cout<<"Energy Sources:\n"; // This prints the energy heading.
        if(energySources.size()==0){ // This checks if there are no energy sources.
            cout<<"No energy sources added yet.\n"; // This prints a helpful message.
        }else{ // This block prints energy source details.
            for(int i=0;i<(int)energySources.size();i++){ // This loop prints every energy source.
                cout<<energySources[i]->getType()<<" | Available Units: "<<energySources[i]->getAvailableEnergy()<<" | Cost/kWh: "<<energySources[i]->getCostPerKWh()<<" | Renewable: "<<(energySources[i]->isRenewable()?"Yes":"No")<<"\n"; // This prints one source line.
            }
        }
    }
};
class SmartEVChargingNetwork{ // This class controls the whole EV charging network.
private:
    vector<User> users; // This stores all users.
    vector<EV> evs; // This stores all EVs.
    vector<ChargingStation> stations; // This stores all stations.
    vector<Booking> bookings; // This stores all bookings.
    vector<Invoice> invoices; // This stores all invoices.
    int nextUserId; // This stores the next user id.
    int nextEVId; // This stores the next EV id.
    int nextStationId; // This stores the next station id.
    int nextBookingId; // This stores the next booking id.
    int nextInvoiceId; // This stores the next invoice id.
    double totalRenewableEnergyUsed; // This stores total renewable energy usage.
    double totalGridEnergyUsed; // This stores total grid energy usage.
    double totalRevenue; // This stores total revenue.
    string currentLanguage; // This future-ready variable allows the interface language to be switched later.
    string getMessage(string key) const{ // This future-ready function centralizes user-facing text so multilingual support can be added later without changing the main logic.
        if(currentLanguage=="EN"){ // This checks English mode.
            if(key=="menu_title") return "SMART EV CHARGING NETWORK"; // This returns English title.
            if(key=="exit") return "Exiting program."; // This returns English exit message.
        }
        if(currentLanguage=="UR"){ // This checks Urdu mode.
            if(key=="menu_title") return "SMART EV CHARGING NETWORK"; // This keeps title simple for this prototype.
            if(key=="exit") return "Program closing."; // This returns an Urdu-style exit message.
        }
        return key; // This returns the key itself if no language entry exists.
    }
    User* findUserById(int id){ // This function finds a user by id.
        for(int i=0;i<(int)users.size();i++){ // This loop checks all users.
            if(users[i].getId()==id){ // This checks id match.
                return &users[i]; // This returns the user's address.
            }
        }
        return nullptr; // This means no matching user was found.
    }
    EV* findEVById(int id){ // This function finds an EV by id.
        for(int i=0;i<(int)evs.size();i++){ // This loop checks all EVs.
            if(evs[i].getId()==id){ // This checks id match.
                return &evs[i]; // This returns the EV address.
            }
        }
        return nullptr; // This means no matching EV was found.
    }
    ChargingStation* findStationById(int id){ // This function finds a station by id.
        for(int i=0;i<(int)stations.size();i++){ // This loop checks all stations.
            if(stations[i].getId()==id){ // This checks id match.
                return &stations[i]; // This returns the station address.
            }
        }
        return nullptr; // This means no matching station was found.
    }
    Booking* findBookingById(int id){ // This function finds a booking by id.
        for(int i=0;i<(int)bookings.size();i++){ // This loop checks all bookings.
            if(bookings[i].getId()==id){ // This checks id match.
                return &bookings[i]; // This returns the booking address.
            }
        }
        return nullptr; // This means no matching booking was found.
    }
    bool stationIdExists(int id) const{ // This function checks whether a station id already exists.
        for(int i=0;i<(int)stations.size();i++){ // This loop checks all stations.
            if(stations[i].getId()==id){ // This checks id match.
                return true; // This means the id already exists.
            }
        }
        return false; // This means the id is free.
    }
    bool dockIdExistsInStation(const ChargingStation& station,int dockId) const{ // This function checks whether a dock id already exists inside a station.
        const vector<ChargingDock>& localDocks=station.getDocks(); // This gets docks safely.
        for(int i=0;i<(int)localDocks.size();i++){ // This loop checks all station docks.
            if(localDocks[i].getId()==dockId){ // This checks id match.
                return true; // This means the dock id already exists.
            }
        }
        return false; // This means the dock id is unique.
    }
    double getMembershipFactor(const string& membership) const{ // This function returns the pricing factor for each membership.
        if(membership=="VIP"){ // This checks VIP.
            return 0.80; // This gives stronger discount.
        }
        if(membership=="Premium"){ // This checks Premium.
            return 0.90; // This gives moderate discount.
        }
        return 1.00; // This keeps regular users at normal rate.
    }
public:
    SmartEVChargingNetwork(){ // This constructor sets default system values.
        nextUserId=1; // This sets next user id.
        nextEVId=1; // This sets next EV id.
        nextStationId=1; // This sets next station id.
        nextBookingId=1; // This sets next booking id.
        nextInvoiceId=1; // This sets next invoice id.
        totalRenewableEnergyUsed=0.0; // This resets renewable usage.
        totalGridEnergyUsed=0.0; // This resets grid usage.
        totalRevenue=0.0; // This resets revenue.
        currentLanguage="EN"; // This starts the system in English mode while keeping it future-ready for more languages.
    }
    void loadSampleData(){ // This function clears old data and loads sample records.
        users.clear(); // This removes old users.
        evs.clear(); // This removes old EVs.
        stations.clear(); // This removes old stations.
        bookings.clear(); // This removes old bookings.
        invoices.clear(); // This removes old invoices.
        nextUserId=1; // This resets next user id.
        nextEVId=1; // This resets next EV id.
        nextStationId=1; // This resets next station id.
        nextBookingId=1; // This resets next booking id.
        nextInvoiceId=1; // This resets next invoice id.
        totalRenewableEnergyUsed=0.0; // This resets renewable usage.
        totalGridEnergyUsed=0.0; // This resets grid usage.
        totalRevenue=0.0; // This resets revenue.
        users.push_back(User(nextUserId++,"Minahil Ahsan Awan","Regular",1)); // This adds user 1.
        users.push_back(User(nextUserId++,"Bushra Ushaq","Premium",2)); // This adds user 2.
        users.push_back(User(nextUserId++,"Saleha Wasim","VIP",3)); // This adds user 3.
        evs.push_back(EV(nextEVId,"Porsche","Car",40.0,35.0,22.0,"Type2")); // This adds EV 1.
        users[0].addVehicle(nextEVId); // This links EV 1 with user 1.
        nextEVId++; // This moves EV id forward.
        evs.push_back(EV(nextEVId,"Mercedes","Car",60.0,20.0,50.0,"CCS",true)); // This adds EV 2 with V2G-ready flag on as a simple demonstration.
        users[1].addVehicle(nextEVId); // This links EV 2 with user 2.
        nextEVId++; // This moves EV id forward.
        evs.push_back(EV(nextEVId,"Lamborghini","Car",75.0,15.0,50.0,"CCS")); // This adds EV 3.
        users[2].addVehicle(nextEVId); // This links EV 3 with user 3.
        nextEVId++; // This moves EV id forward.
        ChargingStation station1(1,"Centaurus Mall","Islamabad",120.0); // This creates station 1.
        station1.addDock(ChargingDock(101,"Slow",7.0,"Type2")); // This adds dock 101.
        station1.addDock(ChargingDock(102,"Medium",22.0,"Type2")); // This adds dock 102.
        station1.addDock(ChargingDock(103,"Fast",50.0,"CCS")); // This adds dock 103.
        station1.addEnergySource(make_shared<SolarPower>(120.0,18.0,0.0)); // This adds solar energy.
        station1.addEnergySource(make_shared<GridPower>(300.0,25.0,0.5)); // This adds grid energy.
        stations.push_back(station1); // This stores station 1.
        ChargingStation station2(2,"PSO","Blue Area",150.0); // This creates station 2.
        station2.addDock(ChargingDock(201,"Slow",7.0,"Type2")); // This adds dock 201.
        station2.addDock(ChargingDock(202,"Medium",22.0,"CCS")); // This adds dock 202.
        station2.addDock(ChargingDock(203,"Fast",50.0,"CCS")); // This adds dock 203.
        station2.addDock(ChargingDock(204,"Fast",50.0,"CHAdeMO")); // This adds dock 204.
        station2.addEnergySource(make_shared<WindPower>(100.0,17.0,0.0)); // This adds wind energy.
        station2.addEnergySource(make_shared<GridPower>(350.0,26.0,0.5)); // This adds grid energy.
        stations.push_back(station2); // This stores station 2.
        nextStationId=3; // This updates next station id.
        cout<<"\nSample data loaded successfully!!\n"; // This confirms success.
        cout<<"This option resets the system and loads ready-made demo users, EVs, stations, docks, and energy sources.\n"; // This explains the feature.
    }
    void registerUser(){ // This function registers a new user.
        cout<<"\n================ REGISTER USER ================\n"; // This prints heading.
        string name=InputHelper::readLine("Enter user name: "); // This reads name.
        string membership=InputHelper::readMembership("Enter membership (Regular/Premium/VIP): "); // This reads membership.
        int priority=InputHelper::readInt("Enter priority level (1 to 3): ",1,3); // This reads priority.
        users.push_back(User(nextUserId,name,membership,priority)); // This stores the new user.
        cout<<"User registered successfully with ID "<<nextUserId<<".\n"; // This confirms success.
        nextUserId++; // This moves user id forward.
    }
    void registerEV(){ // This function registers a new EV.
        cout<<"\n================ REGISTER EV ================\n"; // This prints heading.
        if(users.size()==0){ // This checks whether users exist.
            cout<<"No users found. Please register a user first.\n"; // This prints a helpful message.
            return; // This stops the function.
        }
        showUsersAndVehicles(); // This shows users and EVs.
        int userId=InputHelper::readInt("Enter owner user ID: ",1,1000000); // This reads owner id.
        User* owner=findUserById(userId); // This finds the owner.
        if(owner==nullptr){ // This checks whether owner exists.
            cout<<"User not found.\n"; // This prints an error.
            return; // This stops the function.
        }
        string model=InputHelper::readLine("Enter EV model: "); // This reads model.
        string vehicleType=capitalizeWord(InputHelper::readLine("Enter vehicle type (Car/Bike/Van/Bus/etc.): ")); // This reads type.
        double batteryCapacity=InputHelper::readDouble("Enter battery capacity in kWh (1 to 500): ",1.0,500.0); // This reads capacity.
        double currentSOC=InputHelper::readDouble("Enter current SOC in % (0 to 100): ",0.0,100.0); // This reads SOC.
        double maxChargeRate=InputHelper::readDouble("Enter max charging rate in kW (1 to 500): ",1.0,500.0); // This reads max charge rate.
        string connectorType=InputHelper::readConnector("Enter connector type (Type2/CCS/CHAdeMO): "); // This reads connector.
        bool v2g=InputHelper::readYesNo("Does this EV support V2G in future versions? (yes/no): "); // This reads a future-ready V2G flag.
        evs.push_back(EV(nextEVId,model,vehicleType,batteryCapacity,currentSOC,maxChargeRate,connectorType,v2g)); // This stores the EV.
        owner->addVehicle(nextEVId); // This links EV to owner.
        cout<<"EV registered successfully with ID "<<nextEVId<<".\n"; // This confirms success.
        nextEVId++; // This moves EV id forward.
    }
    void addChargingStation(){ // This function adds a new station.
        cout<<"\n================ ADD CHARGING STATION ================\n"; // This prints heading.
        int stationId=InputHelper::readInt("Enter new station ID: ",1,1000000); // This reads station id.
        if(stationIdExists(stationId)){ // This checks duplicate ids.
            cout<<"Station ID already exists. Please use a different ID.\n"; // This prints an error.
            return; // This stops the function.
        }
        string name=InputHelper::readLine("Enter station name: "); // This reads name.
        string location=InputHelper::readLine("Enter station location: "); // This reads location.
        double capacity=InputHelper::readDouble("Enter station grid capacity in kW (1 to 10000): ",1.0,10000.0); // This reads capacity.
        ChargingStation station(stationId,name,location,capacity); // This creates the station.
        station.addEnergySource(make_shared<GridPower>(capacity*4.0,25.0,0.5)); // This adds default grid energy.
        if(InputHelper::readYesNo("Add solar source as well? (yes/no): ")){ // This checks whether solar should be added.
            double solarEnergy=InputHelper::readDouble("Enter available solar energy in kWh (1 to 100000): ",1.0,100000.0); // This reads solar amount.
            station.addEnergySource(make_shared<SolarPower>(solarEnergy,18.0,0.0)); // This adds solar.
        }
        if(InputHelper::readYesNo("Add wind source as well? (yes/no): ")){ // This checks whether wind should be added.
            double windEnergy=InputHelper::readDouble("Enter available wind energy in kWh (1 to 100000): ",1.0,100000.0); // This reads wind amount.
            station.addEnergySource(make_shared<WindPower>(windEnergy,17.0,0.0)); // This adds wind.
        }
        stations.push_back(station); // This stores the station.
        nextStationId=max(nextStationId,stationId+1); // This safely updates next station id.
        cout<<"Charging station added successfully.\n"; // This confirms success.
    }
    void addDockToStation(){ // This function adds a new dock into an existing station.
        cout<<"\n================ ADD DOCK TO STATION ================\n"; // This prints heading.
        if(stations.size()==0){ // This checks whether stations exist.
            cout<<"No stations found. Please add a station first.\n"; // This prints a helpful message.
            return; // This stops the function.
        }
        showStations(); // This shows stations.
        int stationId=InputHelper::readInt("Enter station ID: ",1,1000000); // This reads station id.
        ChargingStation* station=findStationById(stationId); // This finds the station.
        if(station==nullptr){ // This checks whether station exists.
            cout<<"Station not found.\n"; // This prints an error.
            return; // This stops the function.
        }
        int dockId=InputHelper::readInt("Enter new dock ID: ",1,1000000); // This reads dock id.
        if(dockIdExistsInStation(*station,dockId)){ // This checks duplicate dock ids.
            cout<<"Dock ID already exists in this station.\n"; // This prints an error.
            return; // This stops the function.
        }
        string dockType=InputHelper::readDockType("Enter dock type (Slow/Medium/Fast): "); // This reads dock type.
        double power=InputHelper::readDouble("Enter power rating in kW (1 to 500): ",1.0,500.0); // This reads power.
        string connector=InputHelper::readConnector("Enter connector type (Type2/CCS/CHAdeMO): "); // This reads connector.
        station->addDock(ChargingDock(dockId,dockType,power,connector)); // This adds the dock.
        cout<<"Dock added successfully.\n"; // This confirms success.
    }
    void showStations(){ // This function prints all stations.
        cout<<"\n================ STATIONS ================\n"; // This prints heading.
        if(stations.size()==0){ // This checks whether there are no stations.
            cout<<"No stations available.\n"; // This prints a helpful message.
            return; // This stops the function.
        }
        for(int i=0;i<(int)stations.size();i++){ // This loop prints all stations.
            stations[i].showStationInfo(); // This prints one station.
        }
    }
    void createBooking(){ // This function creates a booking.
        cout<<"\n================ CREATE BOOKING ================\n"; // This prints heading.
        if(users.size()==0||evs.size()==0||stations.size()==0){ // This checks whether core data exists.
            cout<<"Users, EVs, and stations are required before creating a booking.\n"; // This prints a helpful message.
            return; // This stops the function.
        }
        showUsersAndVehicles(); // This shows users and EVs.
        showStations(); // This shows stations.
        int userId=InputHelper::readInt("Enter user ID: ",1,1000000); // This reads user id.
        User* user=findUserById(userId); // This finds the user.
        if(user==nullptr){ // This checks whether user exists.
            cout<<"User not found.\n"; // This prints an error.
            return; // This stops the function.
        }
        int evId=InputHelper::readInt("Enter EV ID: ",1,1000000); // This reads EV id.
        EV* ev=findEVById(evId); // This finds the EV.
        if(ev==nullptr){ // This checks whether EV exists.
            cout<<"EV not found.\n"; // This prints an error.
            return; // This stops the function.
        }
        if(!user->ownsVehicle(evId)){ // This checks whether the EV belongs to the selected user.
            cout<<"This EV does not belong to the selected user.\n"; // This prints an error.
            return; // This stops the function.
        }
        int stationId=InputHelper::readInt("Enter station ID: ",1,1000000); // This reads station id.
        ChargingStation* station=findStationById(stationId); // This finds the station.
        if(station==nullptr){ // This checks whether station exists.
            cout<<"Station not found.\n"; // This prints an error.
            return; // This stops the function.
        }
        int startHour=InputHelper::readInt("Enter start hour (0 to 23): ",0,23); // This reads start hour.
        int durationHours=InputHelper::readInt("Enter duration in hours (1 to 24): ",1,24); // This reads duration.
        double requestedEnergy=ev->getNeededEnergy(); // This calculates requested energy.
        bookings.push_back(Booking(nextBookingId,userId,evId,stationId,startHour,durationHours,user->getPriorityLevel(),requestedEnergy)); // This stores the booking.
        user->addNotification("Booking "+to_string(nextBookingId)+" created successfully."); // This sends a notification.
        cout<<"Booking created successfully with ID "<<nextBookingId<<".\n"; // This confirms success.
        nextBookingId++; // This moves booking id forward.
    }
    void processBooking(){ // This function processes a pending or deferred booking.
        cout<<"\n================ PROCESS BOOKING ================\n"; // This prints heading.
        if(bookings.size()==0){ // This checks whether bookings exist.
            cout<<"No bookings available.\n"; // This prints a helpful message.
            return; // This stops the function.
        }
        showBookings(); // This shows current bookings.
        int bookingId=InputHelper::readInt("Enter booking ID to process: ",1,1000000); // This reads booking id.
        Booking* booking=findBookingById(bookingId); // This finds the booking.
        if(booking==nullptr){ // This checks whether the booking exists.
            cout<<"Booking not found.\n"; // This prints an error.
            return; // This stops the function.
        }
        if(booking->getStatus()!="Pending"&&booking->getStatus()!="Deferred"){ // This allows only pending or deferred bookings.
            cout<<"Only Pending or Deferred bookings can be processed.\n"; // This prints an error.
            return; // This stops the function.
        }
        User* user=findUserById(booking->getUserId()); // This finds the user.
        EV* ev=findEVById(booking->getEVId()); // This finds the EV.
        ChargingStation* station=findStationById(booking->getStationId()); // This finds the station.
        if(user==nullptr||ev==nullptr||station==nullptr){ // This checks data integrity.
            cout<<"Related data is missing for this booking.\n"; // This prints an error.
            return; // This stops the function.
        }
        int dockIndex=station->findBestDockIndex(*ev,booking->getUserPriority()); // This finds the best dock.
        if(dockIndex==-1){ // This checks whether no suitable dock exists.
            booking->markDeferred(); // This defers the booking.
            user->addNotification("Booking "+to_string(booking->getId())+" deferred because no suitable compatible dock was available."); // This notifies the user.
            cout<<"No suitable dock is available. Booking deferred.\n"; // This informs the operator.
            return; // This stops the function.
        }
        int selectedDockIndex=dockIndex; // This stores the selected dock index.
        bool urgentCase=(booking->getUserPriority()>=3||ev->getCurrentSOC()<=30.0); // This checks whether the booking is urgent.
        vector<ChargingDock>& dockList=station->accessDocks(); // This gets controlled internal dock access.
        if(!station->canAcceptLoad(dockList[selectedDockIndex].getPowerRating())){ // This checks whether the preferred dock causes overload.
            if(urgentCase){ // This handles urgent overload case.
                int safeIndex=station->findSafeLowPowerDockIndex(*ev); // This tries a lower-power safe dock as a simple load-shedding policy.
                if(safeIndex!=-1){ // This checks whether a safer dock exists.
                    selectedDockIndex=safeIndex; // This switches to the safer dock.
                }else{ // This handles the case where no safe dock exists.
                    booking->markDeferred(); // This defers the urgent booking.
                    user->addNotification("Booking "+to_string(booking->getId())+" could not start because load shedding prevented overload."); // This notifies the user.
                    cout<<"Load shedding prevented overload, but no safe option was available. Booking deferred.\n"; // This informs the operator.
                    return; // This stops the function.
                }
            }else{ // This handles the non-urgent overload case.
                booking->markDeferred(); // This defers the booking.
                booking->setRequestedStartHour(23); // This shifts the booking to a simple off-peak hour.
                user->addNotification("Booking "+to_string(booking->getId())+" deferred to off-peak time because of high station load."); // This notifies the user.
                cout<<"High load detected. Non-urgent booking deferred to off-peak hour 23.\n"; // This informs the operator.
                return; // This stops the function.
            }
        }
        ChargingDock& dock=dockList[selectedDockIndex]; // This now safely binds the final selected dock.
        bool preferRenewable=!station->isPeakHour(booking->getRequestedStartHour())||booking->getUserPriority()<3; // This decides whether renewable energy should be preferred.
        shared_ptr<EnergySource> source=station->chooseEnergySource(booking->getRequestedEnergy(),preferRenewable); // This selects an energy source.
        if(source==nullptr){ // This checks whether no energy source is available.
            booking->markDeferred(); // This defers the booking.
            user->addNotification("Booking "+to_string(booking->getId())+" deferred because no energy source was available."); // This notifies the user.
            cout<<"No energy source is available for this booking right now.\n"; // This informs the operator.
            return; // This stops the function.
        }
        dock.assignEV(ev->getId()); // This reserves the dock.
        station->addLoad(dock.getPowerRating()); // This adds the dock load to the station.
        booking->setDockAndPower(dock.getId(),dock.getPowerRating()); // This stores dock id and power.
        booking->setEnergySource(source->getType(),source->getCostPerKWh()); // This stores source details.
        booking->markActive(); // This marks the booking active.
        user->addNotification("Booking "+to_string(booking->getId())+" is now active on dock "+to_string(dock.getId())+"."); // This notifies the user.
        cout<<"Booking processed successfully.\n"; // This confirms success.
        cout<<"Assigned Dock ID: "<<booking->getDockId()<<"\n"; // This prints dock id.
        cout<<"Energy Source: "<<booking->getEnergySourceType()<<"\n"; // This prints source.
    }
    void completeChargingSession(){ // This function completes an active charging session and generates the invoice.
        cout<<"\n================ COMPLETE SESSION ================\n"; // This prints heading.
        if(bookings.size()==0){ // This checks whether bookings exist.
            cout<<"No bookings available.\n"; // This prints a helpful message.
            return; // This stops the function.
        }
        showBookings(); // This shows current bookings.
        int bookingId=InputHelper::readInt("Enter booking ID to complete: ",1,1000000); // This reads booking id.
        Booking* booking=findBookingById(bookingId); // This finds the booking.
        if(booking==nullptr){ // This checks whether booking exists.
            cout<<"Booking not found.\n"; // This prints an error.
            return; // This stops the function.
        }
        if(booking->getStatus()!="Active"){ // This ensures only active bookings can be completed.
            cout<<"Only Active bookings can be completed.\n"; // This prints an error.
            return; // This stops the function.
        }
        User* user=findUserById(booking->getUserId()); // This finds the user.
        EV* ev=findEVById(booking->getEVId()); // This finds the EV.
        ChargingStation* station=findStationById(booking->getStationId()); // This finds the station.
        if(user==nullptr||ev==nullptr||station==nullptr){ // This checks data integrity.
            cout<<"Related data is missing for this booking.\n"; // This prints an error.
            return; // This stops the function.
        }
        ChargingDock* dockPointer=nullptr; // This will store the assigned dock.
        vector<ChargingDock>& dockList=station->accessDocks(); // This gets controlled internal dock access.
        for(int i=0;i<(int)dockList.size();i++){ // This loop searches for the assigned dock.
            if(dockList[i].getId()==booking->getDockId()){ // This checks whether the dock matches.
                dockPointer=&dockList[i]; // This stores the dock address.
                break; // This stops the loop.
            }
        }
        if(dockPointer==nullptr){ // This checks whether the dock was found.
            cout<<"Assigned dock not found.\n"; // This prints an error.
            return; // This stops the function.
        }
        shared_ptr<EnergySource> usedSource=nullptr; // This will store the used energy source.
        vector<shared_ptr<EnergySource>>& sourceList=station->accessEnergySources(); // This gets controlled internal source access.
        for(int i=0;i<(int)sourceList.size();i++){ // This loop searches for the energy source.
            if(sourceList[i]->getType()==booking->getEnergySourceType()){ // This checks source match.
                usedSource=sourceList[i]; // This stores the source.
                break; // This stops the loop.
            }
        }
        if(usedSource==nullptr){ // This checks whether the source was found.
            cout<<"Assigned energy source not found.\n"; // This prints an error.
            return; 
        }
        double possibleEnergy=booking->getAssignedPower()*booking->getDurationHours(); // This calculates the maximum energy the dock could deliver.
        double energyConsumed=booking->getRequestedEnergy(); // This starts with requested energy.
        if(possibleEnergy<energyConsumed){ // This checks dock-deliverable limit.
            energyConsumed=possibleEnergy; // This limits energy to dock capacity.
        }
        if(usedSource->getAvailableEnergy()<energyConsumed){ // This checks source availability.
            energyConsumed=usedSource->getAvailableEnergy(); // This limits energy to source availability.
        }
        if(energyConsumed<=0){ // This checks whether any energy can be delivered.
            cout<<"No energy could be delivered because the selected source has no available energy left.\n"; // This prints an error.
            return; // This stops the function.
        }
        double timeFactor=1.00; // This starts with the normal time factor.
        if(station->isPeakHour(booking->getRequestedStartHour())){ // This checks peak hour.
            timeFactor=1.50; // This increases the factor during peak time.
        }
        double speedFactor=1.00; // This starts with the normal speed factor.
        if(booking->getAssignedPower()>22.0){ // This checks fast charging.
            speedFactor=1.40; // This applies fast charging factor.
        }else if(booking->getAssignedPower()>7.0){ // This checks medium charging.
            speedFactor=1.20; // This applies medium charging factor.
        }
        double sourceFactor=1.00; // This starts with the normal source factor.
        if(booking->getEnergySourceType()!="GridPower"){ // This checks renewable source.
            sourceFactor=0.90; // This gives a slight benefit to renewable energy.
        }
        double membershipFactor=getMembershipFactor(user->getMembershipLevel()); // This gets membership factor.
        double finalRatePerKWh=booking->getSourceCostPerKWh()*timeFactor*speedFactor*sourceFactor*membershipFactor; // This calculates the final rate.
        double totalAmount=energyConsumed*finalRatePerKWh; // This calculates the bill.
        usedSource->consumeEnergy(energyConsumed); // This reduces source energy.
        ev->updateSOC(energyConsumed); // This updates EV battery.
        dockPointer->releaseDock(); // This frees the dock.
        station->removeLoad(booking->getAssignedPower()); // This reduces station load.
        booking->markCompleted(); // This marks booking completed.
        if(booking->getEnergySourceType()=="GridPower"){ // This checks grid usage.
            totalGridEnergyUsed=totalGridEnergyUsed+energyConsumed; // This updates grid usage.
        }else{ // This handles renewable usage.
            totalRenewableEnergyUsed=totalRenewableEnergyUsed+energyConsumed; // This updates renewable usage.
        }
        totalRevenue=totalRevenue+totalAmount; // This updates revenue.
        Invoice invoice(nextInvoiceId,booking->getId(),energyConsumed,booking->getDurationHours(),booking->getEnergySourceType(),finalRatePerKWh,totalAmount,timeFactor,speedFactor,sourceFactor,membershipFactor); // This creates the invoice.
        invoices.push_back(invoice); // This stores the invoice.
        invoices[invoices.size()-1].printInvoice(); // This prints the invoice.
        invoices[invoices.size()-1].saveToFile(); // This saves the invoice.
        user->addNotification("Booking "+to_string(booking->getId())+" completed successfully. Invoice "+to_string(nextInvoiceId)+" generated."); // This notifies the user.
        nextInvoiceId++; // This moves invoice id forward.
    }
    void cancelBooking(){ // This function cancels a booking.
        cout<<"\n================ CANCEL BOOKING ================\n"; // This prints heading.
        if(bookings.size()==0){ // This checks whether bookings exist.
            cout<<"No bookings available.\n"; // This prints a helpful message.
            return; // This stops the function.
        }
        showBookings(); // This shows current bookings.
        int bookingId=InputHelper::readInt("Enter booking ID to cancel: ",1,1000000); // This reads booking id.
        Booking* booking=findBookingById(bookingId); // This finds the booking.
        if(booking==nullptr){ // This checks whether booking exists.
            cout<<"Booking not found.\n"; // This prints an error.
            return; // This stops the function.
        }
        if(booking->getStatus()=="Completed"||booking->getStatus()=="Cancelled"){ // This checks non-cancellable states.
            cout<<"This booking cannot be cancelled now.\n"; // This prints an error.
            return; // This stops the function.
        }
        User* user=findUserById(booking->getUserId()); // This finds the user.
        ChargingStation* station=findStationById(booking->getStationId()); // This finds the station.
        if(user==nullptr||station==nullptr){ // This checks data integrity.
            cout<<"Related data is missing for this booking.\n"; // This prints an error.
            return; // This stops the function.
        }
        if(booking->getStatus()=="Active"){ // This checks active cancellation.
            vector<ChargingDock>& dockList=station->accessDocks(); // This gets controlled internal dock access.
            for(int i=0;i<(int)dockList.size();i++){ // This loop searches for the assigned dock.
                if(dockList[i].getId()==booking->getDockId()){ // This checks dock match.
                    dockList[i].releaseDock(); // This frees the dock.
                    break; // This stops the loop.
                }
            }
            station->removeLoad(booking->getAssignedPower()); // This reduces station load.
            booking->markCancelled(50.0); // This applies a larger penalty.
        }else{ // This handles pending or deferred cancellation.
            booking->markCancelled(20.0); // This applies a smaller penalty.
        }
        user->addNotification("Booking "+to_string(booking->getId())+" cancelled. Penalty: "+to_string((int)booking->getCancellationPenalty())); // This notifies the user.
        cout<<"Booking cancelled successfully. Penalty: "<<booking->getCancellationPenalty()<<"\n"; // This confirms success.
    }
    void showBookings(){ // This function prints all bookings.
        cout<<"\n================ BOOKINGS ================\n"; // This prints heading.
        if(bookings.size()==0){ // This checks whether bookings exist.
            cout<<"No bookings available.\n"; // This prints a helpful message.
            return; // This stops the function.
        }
        cout<<fixed<<setprecision(2); // This formats decimals.
        for(int i=0;i<(int)bookings.size();i++){ // This loop prints every booking.
            cout<<"Booking ID: "<<bookings[i].getId()
                <<" | User ID: "<<bookings[i].getUserId()
                <<" | EV ID: "<<bookings[i].getEVId()
                <<" | Station ID: "<<bookings[i].getStationId()
                <<" | Dock ID: "<<bookings[i].getDockId()
                <<" | Start Hour: "<<bookings[i].getRequestedStartHour()
                <<" | Duration: "<<bookings[i].getDurationHours()
                <<" | Requested Energy: "<<bookings[i].getRequestedEnergy()<<"kWh"
                <<" | Assigned Power: "<<bookings[i].getAssignedPower()<<"kW"
                <<" | Source: "<<bookings[i].getEnergySourceType()
                <<" | Status: "<<bookings[i].getStatus()
                <<" | Penalty: "<<bookings[i].getCancellationPenalty()<<"\n"; // This prints one booking line.
        }
    }
    void showAnalyticsReport(){ // This function prints the analytics report.
        cout<<"\n================ ANALYTICS REPORT ================\n"; // This prints heading.
        int totalDocks=0; // This stores total docks.
        int occupiedDocks=0; // This stores occupied docks.
        int peakDemandCount=0; // This stores how many bookings were made for peak hours.
        int offPeakDemandCount=0; // This stores how many bookings were made for off-peak hours.
        for(int i=0;i<(int)stations.size();i++){ // This loop checks all stations.
            totalDocks=totalDocks+stations[i].getTotalDocks(); // This adds dock count.
            occupiedDocks=occupiedDocks+stations[i].getOccupiedDocks(); // This adds occupied dock count.
        }
        int completed=0; // This stores completed bookings.
        int deferred=0; // This stores deferred bookings.
        int cancelled=0; // This stores cancelled bookings.
        int totalDuration=0; // This stores total completed duration.
        for(int i=0;i<(int)bookings.size();i++){ // This loop checks all bookings.
            ChargingStation* station=findStationById(bookings[i].getStationId()); // This finds the related station.
            if(station!=nullptr&&station->isPeakHour(bookings[i].getRequestedStartHour())){ // This checks peak demand.
                peakDemandCount++; // This increases peak demand count.
            }else{ // This handles off-peak demand.
                offPeakDemandCount++; // This increases off-peak demand count.
            }
            if(bookings[i].getStatus()=="Completed"){ // This checks completed bookings.
                completed++; // This increases completed count.
                totalDuration=totalDuration+bookings[i].getDurationHours(); // This adds duration.
            }else if(bookings[i].getStatus()=="Deferred"){ // This checks deferred bookings.
                deferred++; // This increases deferred count.
            }else if(bookings[i].getStatus()=="Cancelled"){ // This checks cancelled bookings.
                cancelled++; // This increases cancelled count.
            }
        }
        double utilization=0.0; // This stores utilization.
        if(totalDocks>0){ // This avoids division by zero.
            utilization=((double)occupiedDocks/totalDocks)*100.0; // This calculates utilization.
        }
        double averageDuration=0.0; // This stores average duration.
        if(completed>0){ // This avoids division by zero.
            averageDuration=(double)totalDuration/completed; // This calculates average duration.
        }
        double renewableGridRatio=0.0; // This stores renewable to grid ratio.
        if(totalGridEnergyUsed>0){ // This avoids division by zero.
            renewableGridRatio=totalRenewableEnergyUsed/totalGridEnergyUsed; // This calculates the ratio.
        }
        double estimatedCO2Savings=totalRenewableEnergyUsed*0.50; // This estimates CO2 savings.
        cout<<fixed<<setprecision(2); // This formats decimals.
        cout<<"Total Stations: "<<stations.size()<<"\n"; // This prints total stations.
        cout<<"Total Docks: "<<totalDocks<<"\n"; // This prints total docks.
        cout<<"Occupied Docks: "<<occupiedDocks<<"\n"; // This prints occupied docks.
        cout<<"Station Utilization: "<<utilization<<"%\n"; // This prints utilization.
        cout<<"Average Session Duration: "<<averageDuration<<" hours\n"; // This prints average duration.
        cout<<"Renewable Energy Used: "<<totalRenewableEnergyUsed<<" kWh\n"; // This prints renewable usage.
        cout<<"Grid Energy Used: "<<totalGridEnergyUsed<<" kWh\n"; // This prints grid usage.
        if(totalGridEnergyUsed>0){ // This checks whether ratio can be printed normally.
            cout<<"Renewable vs Grid Usage Ratio: "<<renewableGridRatio<<"\n"; // This prints ratio.
        }else{ // This handles the case where grid usage is zero.
            cout<<"Renewable vs Grid Usage Ratio: N/A\n"; // This prints a friendly message.
        }
        cout<<"User Demand Trend (Peak Bookings): "<<peakDemandCount<<"\n"; // This prints peak demand trend.
        cout<<"User Demand Trend (Off-Peak Bookings): "<<offPeakDemandCount<<"\n"; // This prints off-peak demand trend.
        cout<<"Total Bookings: "<<bookings.size()<<"\n"; // This prints total bookings.
        cout<<"Completed Bookings: "<<completed<<"\n"; // This prints completed bookings.
        cout<<"Deferred Bookings: "<<deferred<<"\n"; // This prints deferred bookings.
        cout<<"Cancelled Bookings: "<<cancelled<<"\n"; // This prints cancelled bookings.
        cout<<"Total Revenue: "<<totalRevenue<<"\n"; // This prints total revenue.
        cout<<"Estimated CO2 Savings: "<<estimatedCO2Savings<<" kg CO2\n"; // This prints CO2 savings.
        cout<<"Future-ready scalability note: V2G fields, multilingual message layer, and external API extension points are included in the design.\n"; // This prints scalability note.
    }
    void showUsersAndVehicles(){ // This function prints all users and EVs.
        cout<<"\n================ USERS AND EVs ================\n"; // This prints heading.
        if(users.size()==0){ // This checks whether users exist.
            cout<<"No users available.\n"; // This prints a helpful message.
            return; // This stops the function.
        }
        for(int i=0;i<(int)users.size();i++){ // This loop prints every user.
            cout<<"User ID: "<<users[i].getId()<<" | Name: "<<users[i].getName()<<" | Membership: "<<users[i].getMembershipLevel()<<" | Priority: "<<users[i].getPriorityLevel()<<" | EV IDs: "; // This prints user details.
            const vector<int>& ids=users[i].getVehicleIds(); // This gets EV ids safely.
            if(ids.size()==0){ // This checks whether the user has no EVs.
                cout<<"None"; // This prints none.
            }else{ // This block prints EV ids.
                for(int j=0;j<(int)ids.size();j++){ // This loop prints every EV id.
                    cout<<ids[j]; // This prints one EV id.
                    if(j+1<(int)ids.size()){ // This checks whether a separator is needed.
                        cout<<", "; // This prints the separator.
                    }
                }
            }
            cout<<"\n"; // This moves to next line.
        }
        cout<<"EV Details:\n"; // This prints EV heading.
        if(evs.size()==0){ // This checks whether EVs exist.
            cout<<"No EVs available.\n"; // This prints a helpful message.
        }else{ // This block prints EV details.
            for(int i=0;i<(int)evs.size();i++){ // This loop prints every EV.
                cout<<"EV ID: "<<evs[i].getId()<<" | Model: "<<evs[i].getModel()<<" | Type: "<<evs[i].getVehicleType()<<" | Capacity: "<<evs[i].getBatteryCapacity()<<"kWh | SOC: "<<evs[i].getCurrentSOC()<<"% | Max Rate: "<<evs[i].getMaxChargeRate()<<"kW | Connector: "<<evs[i].getConnectorType()<<" | V2G Ready: "<<(evs[i].isV2GEnabled()?"Yes":"No")<<"\n"; // This prints one EV line.
            }
        }
    }
    void showUserNotifications(){ // This function prints notifications of one selected user.
        cout<<"\n================ USER NOTIFICATIONS ================\n"; // This prints heading.
        if(users.size()==0){ // This checks whether users exist.
            cout<<"No users available.\n"; // This prints a helpful message.
            return; // This stops the function.
        }
        int userId=InputHelper::readInt("Enter user ID: ",1,1000000); // This reads user id.
        User* user=findUserById(userId); // This finds the user.
        if(user==nullptr){ // This checks whether the user exists.
            cout<<"User not found.\n"; // This prints an error.
            return; // This stops the function.
        }
        user->showNotifications(); // This prints notifications.
    }
    void showMenu(){ // This function prints the main menu.
        cout<<"\n================ "<<getMessage("menu_title")<<" ================\n"; // This prints title through the centralized message layer.
        cout<<"1. Load sample data\n"; // This prints option 1.
        cout<<"2. Register user\n"; // This prints option 2.
        cout<<"3. Register EV\n"; // This prints option 3.
        cout<<"4. Add charging station\n"; // This prints option 4.
        cout<<"5. Add dock to station\n"; // This prints option 5.
        cout<<"6. Show stations and dock availability\n"; // This prints option 6.
        cout<<"7. Create booking\n"; // This prints option 7.
        cout<<"8. Process booking\n"; // This prints option 8.
        cout<<"9. Complete charging session and generate invoice\n"; // This prints option 9.
        cout<<"10. Cancel booking\n"; // This prints option 10.
        cout<<"11. Show all bookings\n"; // This prints option 11.
        cout<<"12. Show analytics report\n"; // This prints option 12.
        cout<<"13. Show users and EVs\n"; // This prints option 13.
        cout<<"14. Show user notifications\n"; // This prints option 14.
        cout<<"0. Exit\n"; // This prints option 0.
    }
    void run(){ // This function runs the whole menu system.
        while(true){ // This loop keeps running until the user chooses to exit.
            showMenu(); // This prints the menu.
            int choice=InputHelper::readInt("Enter your choice: ",0,14); // This safely reads menu choice.
            if(choice==0){ // This checks exit.
                cout<<getMessage("exit")<<"\n"; // This prints exit message through the message layer.
                break; // This ends the loop.
            }
            if(choice==1){ // This handles option 1.
                loadSampleData(); // This loads sample data.
            }else if(choice==2){ // This handles option 2.
                registerUser(); // This registers a user.
            }else if(choice==3){ // This handles option 3.
                registerEV(); // This registers an EV.
            }else if(choice==4){ // This handles option 4.
                addChargingStation(); // This adds a station.
            }else if(choice==5){ // This handles option 5.
                addDockToStation(); // This adds a dock.
            }else if(choice==6){ // This handles option 6.
                showStations(); // This shows stations.
            }else if(choice==7){ // This handles option 7.
                createBooking(); // This creates a booking.
            }else if(choice==8){ // This handles option 8.
                processBooking(); // This processes a booking.
            }else if(choice==9){ // This handles option 9.
                completeChargingSession(); // This completes a session.
            }else if(choice==10){ // This handles option 10.
                cancelBooking(); // This cancels a booking.
            }else if(choice==11){ // This handles option 11.
                showBookings(); // This shows bookings.
            }else if(choice==12){ // This handles option 12.
                showAnalyticsReport(); // This shows analytics.
            }else if(choice==13){ // This handles option 13.
                showUsersAndVehicles(); // This shows users and EVs.
            }else if(choice==14){ // This handles option 14.
                showUserNotifications(); // This shows notifications.
            }
        }
    }
};
int main(){ // This is the program entry point.
    SmartEVChargingNetwork system; // This creates the main system object.
    system.run(); // This starts the menu-based program.
    return 0; // This ends the program successfully.
}