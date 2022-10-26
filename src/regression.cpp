#include "regression.h"

Data regression::read_database(std::string filepath)
{
    Data TrainingMatrix;
    std::string line;
    std::ifstream inventory;
    inventory.open(filepath);
    if (!inventory)
    {
        throw std::runtime_error("the file path is not here");
    }
    while (std::getline(inventory, line))
    {
        std::vector<double> AFish;
        size_t place{line.find(",")};
        AFish.push_back(1);
        while (place <= line.length())
        {
            AFish.push_back(std::stod(line.substr(0, place)));
            line.erase(0, place + 1);
            place = line.find(",");
        }
        AFish.push_back(std::stod(line));
        TrainingMatrix.push_back(AFish);
    }
    return TrainingMatrix;
}

double regression::hypothesis(std::vector<double> theta, std::vector<double> x)
{
    if (theta.size() != x.size())
    {
        throw std::logic_error("The size of the two matrixs are not equal!");
    }
    double hypo{0.0};
    size_t count{0};
    for (auto teta : theta)
    {
        hypo += teta * x[count];
        count++;
    }
    return hypo;
}

double regression::cost_function(Data dataset, std::vector<double> theta)
{
    double sum{0};
    for (auto row : dataset)
    {
        sum += (hypothesis({row[0], row[1], row[2], row[3]}, theta) - row[4]) * (hypothesis({row[0], row[1], row[2], row[3]}, theta) - row[4]);
    }
    return 0.5 * sum;
}

std::vector<double> regression::update(Data dataset, std::vector<double> theta, double lr)
{
    std::vector<double> Newtheta;
    double Atheta{0};
    size_t count{0};
    double sum{0};

    for (auto Tj : theta)
    {

        for (auto row : dataset)
        {
            sum += (hypothesis({row[0], row[1], row[2], row[3]}, theta) - row[4]) * row[count];
        }
        Atheta = Tj - (lr * sum);
        Newtheta.push_back(Atheta);
        count++;
    }
    return Newtheta;
}

std::vector<double> regression::linear_regression(Data dataset, std::vector<double> init_theta, double lr)
{
    double FormerCost{0};
    FormerCost = cost_function(dataset, init_theta);
    std::vector<double> Next_theta;
    Next_theta = update(dataset, init_theta, lr);
    for (size_t i{1}; i <= 10000; i++)
    {
        double newCost{cost_function(dataset, Next_theta)};
        std::cout << i << "  ->  cost: " << newCost << "      -reduced cost : " << (FormerCost - newCost) << std::endl;
        Next_theta = update(dataset, Next_theta, lr);
        FormerCost = newCost;
    }
    return Next_theta;
}