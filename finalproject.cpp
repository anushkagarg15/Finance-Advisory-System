#include <bits/stdc++.h>
using namespace std;

class Transaction;
class Income;
class Expenditure;
class Investment;
class SIP;
class FD;
class FinanceManager;
class Bank;
class BankAdvisor;
class User;
class ReviewSystem;
class InvestmentPlanner;


//Base class for transactions
class Transaction
{
public:
    virtual void display() const = 0;
    virtual ~Transaction() = default;
};

//Derived class for income transactions
class Income : public Transaction
 {
public:
    double amount;
    string description;
    Income(double amt, const string& desc)
        {
            amount=amt;
            description=desc;
        }
    void display() const override {
        cout<<setw(15)<<"Income"<<setw(15)<<amount<<setw(30)<<description<<endl;
    }
};

//Derived class for expenditure transactions
class Expenditure : public Transaction {
public:
    double amount;
    string description;
    Expenditure(double amt, const string& desc)
    {
         amount=amt;
         description=desc;
    }
    void display() const override {
        cout<<setw(15)<<"Expenditure"<<setw(15)<<amount<<setw(30)<<description<<endl;
    }
};

//Base class for investments
class Investment {
public:
    virtual void display() const = 0;
    virtual ~Investment() = default;
};

//Derived class for SIP investments
class SIP : public Investment {
public:
    double amount;
    int duration;
    double monthlyContribution;
    SIP(double amt, int dur, double monthly) {
        amount=amt;
        duration=dur;
        monthlyContribution=monthly;
    }
    void display() const override {
        cout<<setw(15)<<"SIP"<<setw(15)<<amount<<setw(15)<<duration<<setw(30)<<monthlyContribution<<endl;
    }
};

//Derived class for FD investments
class FD : public Investment
 {
public:
    double amount;
    int duration;
    FD(double amt, int dur)
    {
        amount=amt;
        duration=dur;
    }
    void display() const override
    {
        cout<<setw(15)<<"FD"<<setw(15)<<amount<<setw(15)<<duration<<setw(30)<<"-"<<endl;
    }
};

//FinanceManager class to manage transactions and investments
class FinanceManager
{
public:
    vector<shared_ptr<Transaction>> transactions;
    vector<shared_ptr<Investment>> investments;

    void addTransaction(Transaction* t)
    {
        transactions.push_back(shared_ptr<Transaction>(t));
    }

    void addInvestment(Investment* inv)
    {
        investments.push_back(shared_ptr<Investment>(inv));
    }

    void displayTransactions() const
    {
        cout << "\n----- DISPLAYING TRANSACTIONS -----\n";
        cout << setw(15) << "Type" << setw(15) << "Amount" << setw(30) << "Description" << endl;
        for (const auto& t : transactions) {
            t->display();
        }
    }

    void displayInvestments() const
    {
        cout << "\n----- DISPLAYING INVESTMENTS -----\n";
        cout << setw(15) << "Type" << setw(15) << "Amount" << setw(15) << "Duration" << setw(30) << "Monthly Contribution" << endl;
        for (const auto& inv : investments) {
            inv->display();
        }
    }
};

//Bank class to store bank details
class Bank
 {
public:
    string name;
    string sector;
    string accTypes;
    string minBal;
    double savingsInterestRate;
    string loans;
    string digitalServices;
    double fdInterestRate;
    double emiInterestRate;

    Bank(const string& n, const string& s, const string& acc, const string& min, double savingsRate, const string& l, const string& digital, double fdRate, double emiRate)
        {
            name=n;
            sector=s;
            accTypes=acc;
            minBal=min;
            savingsInterestRate=savingsRate;
            loans=l;
            digitalServices=digital;
            fdInterestRate=fdRate;
            emiInterestRate=emiRate;
        }

    void display() const
    {
        cout<<setw(15)<<name<<setw(20)<<fixed<<setprecision(2)<<emiInterestRate<<setw(20)<<fixed<<setprecision(2)<<fdInterestRate<<"\t\t"<<fixed<<setprecision(2)<<savingsInterestRate<<endl;
    }

    void updateDetail(const string& field)
    {
        if (field == "name")
            {
            cin.ignore();
            cout<<"Enter new name: ";
            getline(cin, name);
            }
        else if (field == "sector")
            {
            cin.ignore();
            cout<<"Enter new sector: ";
            getline(cin, sector);
            }
        else if (field == "accTypes")
            {
            cin.ignore();
            cout<<"Enter new account types: ";
            getline(cin, accTypes);
            }
        else if (field == "minBal")
            {
            cin.ignore();
            cout<<"Enter new minimum balance: ";
            getline(cin, minBal);
            }
        else if (field == "savingsInterestRate")
            {
            cout<<"Enter new savings interest rate: ";
            cin>>savingsInterestRate;
            }
        else if (field == "loans")
            {
            cin.ignore();
            cout<<"Enter new loan types: ";
            getline(cin, loans);
            }
        else if (field == "digitalServices")
            {
            cin.ignore();
            cout<<"Enter new digital services: ";
            getline(cin, digitalServices);
            }
        else if (field == "fdInterestRate")
            {
            cout<<"Enter new FD interest rate: ";
            cin>>fdInterestRate;
            }
        else if (field == "emiInterestRate")
            {
            cout<<"Enter new EMI interest rate: ";
            cin>>emiInterestRate;
            }
        else
            {
            cout<<"Invalid field name.\n";
            }
    }
};

//BankAdvisor class to manage a collection of banks
class BankAdvisor
{
public:
    vector<shared_ptr<Bank>> banks;

    void addBank(shared_ptr<Bank> bank)
    {
        banks.push_back(bank);
    }

    void displayBanks() const
    {
        cout<<"\n--------------BANK DETAILS------------------------\n";
        cout<<setw(15) << "Bank Name " << setw(20) << "EMI Interest Rate" << setw(20) << "FD Interest Rate \t Savings Interest Rate" << endl;
        for (const auto& bank : banks) {
            bank->display();
        }
    }

    void recommendBestFD() const
    {
        if (banks.empty())
        {
            cout << "OOPS!! No banks available. \n";
            return;
        }

        auto best = banks[0];
        for (const auto& bank : banks)
        {
            if (bank->fdInterestRate > best->fdInterestRate) {
                best = bank;
            }
        }

        cout<<"\nBest Bank for Fixed Deposit (FD) ---> " << best->name << endl;
        cout<<" FD Rate: " << fixed << setprecision(2) << best->fdInterestRate << "%" << endl;
    }

    void recommendBestSavings() const
     {
        if (banks.empty())
        {
            cout << "OOPS!! No banks available. \n";
            return;
        }

        auto best = banks[0];
        for (const auto& bank : banks)
        {
            if (bank->savingsInterestRate > best->savingsInterestRate) {
                best = bank;
            }
        }

        cout<<"\nBest Bank for Savings Account ---> "<<best->name<<endl;
        cout<<"Savings Rate (in %) : "<<fixed<<setprecision(2)<<best->savingsInterestRate<<endl;
    }

    void recommendBestEMI() const
    {
        if (banks.empty())
        {
            cout<<"OOPS!! No banks available. \n";
            return;
        }

        auto best = banks[0];
        for (const auto& bank : banks)
            {
            if (bank->emiInterestRate < best->emiInterestRate)
            {
                best = bank;
            }
        }

        cout<<"\nBest Bank for Loan EMI ---> "<<best->name<<endl;
        cout<<" EMI Interest Rate: (in %)"<<fixed<<setprecision(2)<<best->emiInterestRate<<endl;
    }


    void addBankInteractive()
    {
        int n_banks;
        cout<<"Enter number of banks to add: ";
        cin>>n_banks;
        cin.ignore();

        for (int i=0; i<n_banks; i++) {
            string name, sector, accTypes, minBal, loans, digital;
            double savingsRate, fdRate, emiRate;

            cout<<"\nBank #" << i + 1 << ":\n";
            cout<<"Bank Name: ";
            getline(cin, name);

            cout<<"Sector (Public/Private): ";
            getline(cin, sector);

            cout<<"Account Types (comma separated): ";
            getline(cin, accTypes);

            cout<<"Minimum Balance: ";
            getline(cin, minBal);

            cout<<"Savings Interest Rate (%): ";
            cin>>savingsRate;
            cin.ignore();

            cout<<"FD Interest Rate (%): ";
            cin>>fdRate;
            cin.ignore();

            cout<<"EMI Interest Rate (%): ";
            cin>>emiRate;
            cin.ignore();

            cout<<"Loans Provided: ";
            getline(cin, loans);

            cout<<"Digital Services Provided (Yes/No): ";
            getline(cin, digital);

            shared_ptr<Bank> newBank = make_shared<Bank>(
                name, sector, accTypes, minBal, savingsRate, loans, digital, fdRate, emiRate
            );

            banks.push_back(newBank);
        }

        cout << "\nBanks added successfully!\n";
    }
    void deleteBank()
 {
    if (banks.empty())
    {
        cout << "No such  bank is currently available to be deleted"<<endl ;
        return;
    }

    string name;
    cout << "-----------------------------\n";
    cout << " Enter the name of the bank you want to delete: ";
    cin.ignore();
    getline ( cin , name );

    bool found = false;

    for (int i = 0; i < banks.size(); ++i) {
        if ( banks [i]->name == name)
       {
            cout << "\nBank found:\n";
            banks[i]->display();

            char want;
            cout << " Are you sure you want to delete this bank ? (y/n): ";
            cin >> want;

            if (want == 'y' || want== 'Y')
            {
                banks.erase(banks.begin() + i);
                cout << " Bank \"" << name << "\" has been deleted successfully. \n";
            }
            else
             {
                cout << "Deletion has been cancelled.\n";
             }
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Bank \"" << name << "\" not found in the system.\n";
    }

    cout << "-----------------------------\n";
}
        void updateDetail(const string& field)
        {
                if (banks.empty())
                {
                cout << "No banks available to update.\n";
                return;
                }

                cout << "Available banks:\n";
                for (size_t i = 0; i < banks.size(); ++i)
                {
                cout << i + 1 << ". " << banks[i]->name << endl;
                }

            cout << "Enter the number of the bank you want to update: ";
            size_t index;
            cin >> index;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (index < 1 || index > banks.size())
            {
            cout << "Invalid index.\n";
            return;
            }

            banks[index - 1]->updateDetail(field);
        }

};

//Review System class to handle user feedback
class ReviewSystem {
public:
    void submitReview() const
    {
        cout << "\n----- SYSTEM REVIEW -----\n";
        cout << "Please provide your feedback on the Finance Management System:\n";
        string feedback;
        cin.ignore();
        getline(cin, feedback);

        ofstream reviewFile("system_review.txt", ios::app);
        if (reviewFile.is_open())
        {
            reviewFile<<feedback<<endl;
            reviewFile.close();
            cout<<"Thank you for your valuable feedback!\n";
        }
        else
        {
            cerr<<"Error: Could not open file to save review.\n";
        }
    }

    void displayReviews() const
    {
        cout<<"\n----- USER REVIEWS -----\n";
        ifstream reviewFile("system_review.txt");
        if (reviewFile.is_open()) {
            string line;
            while (getline(reviewFile, line)) {
                cout<<"- "<<line<<endl;
            }
            reviewFile.close();
            if (ifstream("system_review.txt").peek() == ifstream::traits_type::eof()) {
                cout<<"No user reviews available yet.\n";
            }
        } else {
            cerr<<"Error: Could not open file to read reviews.\n";
        }
    }
};

//InvestmentPlanner class to provide investment advice
class InvestmentPlanner
 {
    public:
    double riskTolerance;
    double investmentHorizon;
    double initialInvestment;
    double monthlyContribution;

    InvestmentPlanner() {
        riskTolerance=3;
        investmentHorizon=10;
        initialInvestment=0;
        monthlyContribution=0;
        }


    void getUserPreferences() {
        cout<<"\n----- INVESTMENT PLANNER -----\n";
        cout<<"Enter your risk tolerance (1-5, Low to High): ";

        while (!(cin>>riskTolerance) || riskTolerance<1 || riskTolerance>5) {
            cout<<"Invalid input. Please enter a number between 1 and 5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout<<"Enter your investment horizon (in years): ";

        while (!(cin>>investmentHorizon) || investmentHorizon<=0)
        {
            cout<<"Invalid input. Please enter a positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout<<"Enter your initial investment amount: ";

         while (!(cin>>initialInvestment) || initialInvestment<0)
        {
            cout<<"Invalid input. Please enter a non-negative number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout<<"Enter your monthly contribution amount: ";

        while (!(cin >> monthlyContribution) || monthlyContribution < 0)
        {
            cout<<"Invalid input. Please enter a non-negative number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear any extra input
    }

    void generateInvestmentPlan() const {
        cout<<"\n----- INVESTMENT PLAN RECOMMENDATION -----\n";

        if (riskTolerance<=2)
        {
            cout<<"Based on your low risk tolerance, we recommend a conservative portfolio:\n";
            cout<<"- High allocation to Fixed Deposits (FDs) for stable returns.\n";
            cout<<"- Some investment in government bonds or low-risk mutual funds.\n";
            cout<<"- Consider a small allocation to balanced mutual funds for moderate growth.\n";
        }

        else if (riskTolerance<=4)
        {
            cout<<"Based on your moderate risk tolerance, we recommend a balanced portfolio:\n";
            cout<<"- Balanced allocation to equity mutual funds and debt funds.\n";
            cout<<"- Consider a Systematic Investment Plan (SIP) in diversified equity funds.\n";
            cout<<"- Include corporate bonds and other fixed-income instruments for stability.\n";
        }

        else
        {
            cout<<"Based on your high risk tolerance, we recommend an aggressive growth portfolio:\n";
            cout<<"- Significant allocation to equity mutual funds with high growth potential.\n";
            cout<<"- Consider investments in sector-specific or thematic funds.\n";
            cout<<"- Explore alternative investment options like REITs or international equities for diversification.\n";
        }

        cout<<"\nGeneral Recommendations:\n";
        cout<<"- Diversify your investments across different asset classes to reduce risk.\n";
        cout<<"- Regularly review and rebalance your portfolio to maintain your desired asset allocation.\n";
        cout<<"- Consider your investment horizon. Longer horizons allow for more aggressive strategies.\n";
        cout<<"- Consult with a financial advisor for personalized advice.\n";
    }

     void displayInvestmentOptions(){
        cout<<"\n----- INVESTMENT OPTIONS -----\n";
        cout<<"Here are some general investment options you can consider:\n";

        cout<<"1. Equity Mutual Funds: \n";
        cout<<"            Invest in a diversified portfolio of stocks. Suitable for long-term goals and higher risk tolerance.\n ";

        cout<<"\n2. Debt Funds:\n";
        cout<<"            Invest in fixed-income securities like bonds. Offer stability and regular income. Suitable for lower risk tolerance\n ";

        cout<<"\n3. Fixed Deposits (FDs): \n";
        cout<<"            Offer guaranteed returns over a fixed period. Low risk and suitable for short to medium-term goals.\n";


        cout<<"\n4. Systematic Investment Plan (SIP): \n";
        cout<<"            Invest a fixed amount regularly in mutual funds. Helps in rupee-cost averaging and disciplined investing.\n";

        cout<<"\n5. Government Bonds: \n";
        cout<<"            Low-risk investments issued by the government. Provide stable returns.\n";

        cout<<"\n6. Corporate Bonds: \n";
        cout<<"            Bonds issued by companies. Carry a slightly higher risk than government bonds but offer better returns.\n";

        cout<<"\n7. Real Estate Investment Trusts (REITs): \n";
        cout<<"            Invest in a portfolio of income-producing real estate properties.\n";

        cout<<"\n8. International Equities: \n";
        cout<<"            Invest in stocks of companies located in other countries for diversification.\n";

        cout<<"\nRemember to research thoroughly and understand the risks associated with each investment option before investing.\n";
    }
};

//User class to manage user balance and financial activities
class User
{
public:
    FinanceManager manager;
    double balance;
    BankAdvisor advisor;
    ReviewSystem reviewSystem;
    InvestmentPlanner planner;

    User(double initialBalance)
         {
            balance=initialBalance;
         }

   void recordIncome() {
        double amt;
        string desc;
        cout<<"Enter amount: ";
        cin>>amt;
        cout<<"Enter description: ";
        cin.ignore();
        getline(cin, desc);
        manager.addTransaction(new Income(amt, desc));
        balance += amt;
        cout<<">>> Income Recorded Successfully!\n";
    }

    void recordExpenditure() {
        double amt;
        string desc;
        cout<<"\n-- RECORD EXPENDITURE --\n";
        cout<<"Enter amount: ";
        cin>>amt;
        if (balance - amt < 1000) {
            cout<<"OOPS!! Error: Balance cannot go below 1000.\n";
            return;
        }
        cin.ignore();
        cout<<"Enter description: ";
        getline(cin, desc);
        manager.addTransaction(new Expenditure(amt, desc));
        balance -= amt;
        cout<<">>> Expenditure Recorded Successfully!\n";
    }

    void makeInvestment() {
        int sub = -1;
        while (sub != 0) {
            cout<<endl;
            cout<<"               -- MAKE INVESTMENT --\n";
            cout<<"------------------------------------------------\n";
            cout<<"1. SIP"<<endl;
            cout<<"2. Fixed Deposit (FD)"<<endl;
            cout<<"0. Back to Menu"<<endl;
            cout<<endl;
            cout<<"Enter choice: ";
            cin>>sub;

            double amt;
            int dur;
            switch (sub) {
                case 1:
                    cout<<"Enter amount to invest: ";
                    cin>>amt;
                    cout<<"Enter duration (in years): ";
                    cin>>dur;
                    if (amt>balance) {
                        cout<<"OOPS! You don't have enough balance for this investment.\n";
                    } else {
                        double monthly;
                        cout<<"Enter SIP monthly contribution: ";
                        cin>>monthly;
                        balance -= amt;
                        manager.addInvestment(new SIP(amt, dur, monthly));
                        cout<<"Investment made in SIP!\n";
                    }
                    break;

                case 2:
                    cout<<"Enter amount to invest: ";
                    cin>>amt;
                    cout<<"Enter duration (in years): ";
                    cin>>dur;
                    if (amt>balance)
                    {
                        cout<<"OOPS! You don't have enough balance for this investment.\n";
                    }
                    else
                    {
                        balance -= amt;
                        manager.addInvestment(new FD(amt, dur));
                        cout<<"Investment made in Fixed Deposit (FD)!\n";
                    }
                    break;

                case 0:
                    return;

                default:
                    cout<<"Invalid choice!\n";
                    break;
            }
        }
    }

    void displayInvestmentInfo()
    {
        manager.displayInvestments();
    }

    void displayTransactions()
    {
        manager.displayTransactions();
    }

    void calculateEMI() const;
    void calculateFDInterestSimple() const;
    void calculateFDInterestCompound() const;
    void submitReview() const
    {
        reviewSystem.submitReview();
    }
    void displayReviews() const
    {
        reviewSystem.displayReviews();
    }

    void viewInvestmentPlan()
    {
        planner.getUserPreferences();
        planner.generateInvestmentPlan();
    }

    void viewInvestmentOptions()
    {
        planner.displayInvestmentOptions();
    }
};

void User::calculateEMI() const
{
    double p, r, e=0;
    int n, c;
    cout<<"Enter the principal amount : ";
    cin>>p;
    cout<<"Enter the rate of interest  annually (in %): ";
    cin>>r;
    r=r/100.0;
    cout<<"Calculate EMI:\n1 - Annually\n2 - Monthly\n3 - Quarterly\n";
    cin>>c;
    if (c==3) {
        r=r / 4.0;
        cout<<"Enter the  number of quarters : ";
        cin>>n;
    } else if (c==2) {
        r=r/12.0;
        cout<<"Enter the  number of months : ";
        cin>>n;
    } else {
        cout<<"Enter the  number of years : ";
        cin>>n;
    }
    e = p*r*(pow(1 + r, n)/(pow((1 + r), n) - 1));
    cout<<"EMI calculated : "<<fixed<<setprecision(2)<<e<<endl;
}

void User::calculateFDInterestSimple() const
{
    double p, r, i=0;
    int n;
    cout<<"Enter the principal amount : ";
    cin>>p;
    cout<<"Enter the rate of interest  annually (in %): ";
    cin>>r;
    r=r/100.0;
    cout<<"Enter the  number of years : ";
    cin>>n;
    i=p*r*n;
    double m=i+p;
    cout<<"Simple Interest : "<<fixed<<setprecision(2)<<i<<endl;
    cout<<"Maturity amount : "<<fixed<<setprecision(2)<<m<<endl;
}

void User::calculateFDInterestCompound() const
{
    double p, r, i=0;
    int n, t;
    cout<<"Enter the principal amount : ";
    cin>>p;
    cout<<"Enter the rate of interest  annually (in %): ";
    cin>>r;
    r=r/100.0;
    cout << "Enter the  number of years : ";
    cin>>t;
    cout << "Enter the  number of times interest is compounded per year : ";
    cin>>n;
    double m=p*pow((1 + r / n), (n * t));
    i=m-p;
    cout<<"Compound Interest : "<<fixed<<setprecision(2)<<i<<endl;
    cout<<"Maturity amount : "<<fixed<<setprecision(2)<<m<<endl;
}

int main()
{
    
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "|                     Finance Management and Advisory System                       |" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    

    User user(10000);

    user.advisor.addBank(make_shared<Bank>("SBI", "Public", "Savings, Current", "Rs. 5000", 3.0, "Home Loan, Vehicle Loan", "Yes", 5.5, 6.8));
    user.advisor.addBank(make_shared<Bank>("HDFC", "Private", "Savings, Current", "Rs. 2500",3.5, "Home Loan, Personal Loan", "Yes", 7.0, 7.9));
    user.advisor.addBank(make_shared<Bank>("Axis", "Private", "Savings, Current", "Rs. 10000", 4.0, "All Loans", "Yes", 6.5, 7.5));

    int choice = -1;
    while (choice != 0) {
        cout<<"\n---------------------- MENU ----------------------\n";
        cout<<"1. Record Income\n";
        cout<<"2. Record Expenditure\n";
        cout<<"3. Make Investment\n";
        cout<<"4. View Transactions\n";
        cout<<"5. View Investments\n";
        cout<<"6. View Banks & Recommendations\n";
        cout<<"7. Add Bank\n";
        cout<<"8. Update Bank Details\n";
        cout<<"9. Remove Bank\n";
        cout<<"10. Calculate EMI\n";
        cout<<"11. Calculate Simple FD Interest\n";
        cout<<"12. Calculate Compound FD Interest\n";
        cout<<"13. Submit System Review\n";
        cout<<"14. View System Reviews\n";
        cout<<"15. View Investment Plan\n";
        cout<<"16. View Investment Options\n";
        cout<<"0. Exit\n";
        cout<<"--------------------------------------------------\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice)
        {
            case 1:
                user.recordIncome();
            break;

            case 2:
                user.recordExpenditure();
            break;

            case 3:
                user.makeInvestment();
            break;

            case 4:
                user.displayTransactions();
            break;

            case 5:
                 user.displayInvestmentInfo();
                 break;

            case 6:
                user.advisor.displayBanks();
                user.advisor.recommendBestFD();
                user.advisor.recommendBestSavings();
                user.advisor.recommendBestEMI();
                break;

            case 7:
                    user.advisor.addBankInteractive();
                    break;

            case 8:
                {
                    string fieldToUpdate;
                    cout<<"Enter the field name to update: ";
                    cin>>fieldToUpdate;
                    user.advisor.updateDetail(fieldToUpdate);
                    break;
                }

            case 9:
                    user.advisor.deleteBank();
                    break;

            case 10:
                user.calculateEMI();
                break;

            case 11:
                user.calculateFDInterestSimple();
                break;

            case 12:
                user.calculateFDInterestCompound();
                break;

            case 13:
                user.submitReview();
                 break;

            case 14:
                user.displayReviews();
                break;

            case 15:
                user.viewInvestmentPlan();
                break;

            case 16:
                user.viewInvestmentOptions();
                break;

            case 0:
                cout<<"Exiting...\n";
                break;

            default:
                 cout<<"Invalid choice!\n";
                  break;
        }
    }

    return 0;
}
