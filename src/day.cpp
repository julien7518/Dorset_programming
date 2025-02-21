#include <iostream>

int main() {
  // Question 1
  std::string day;
  std::cout << "Enter a day with an upper first case : ";
  std::cin >> day;
  if (day == "Saturday" || day == "Sunday") {
    std::cout << day + " is weekend.";
  }
  else {
    std::cout << day + " is working day.";
  }

  // Question 2
  int d;
  std::cout << "\n\nEnter a day number (1 for Monday, 7 for Sunday) : ";
  std::cin >> d;
  switch (d)
  {
  case 6:
    std::cout << "It's the weekend.";
    break;
  case 7:
    std::cout << "It's the weekend.";
    break;

  default:
    std::cout << "It's a working day.";
    break;
  }
  
  return 0;
}
