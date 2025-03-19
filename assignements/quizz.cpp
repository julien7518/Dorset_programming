#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Choice
{
    char letter;
    string text;
};

struct Question
{
    string question;
    Choice choices[4];
    char answer;
};

struct Subtopic
{
    string name;
    Question questions[10];
};

struct Quizz
{
    Subtopic subtopics[5];
};

Quizz quizz_content = {
    subtopics : {
        {
            name : "Histoire de la Révolution française",
            questions : {
                {
                    question : "In which year did the French Revolution begin?",
                    choices : {{'A', "1776"},
                               {'B', "1789"},
                               {'C', "1804"},
                               {'D', "1815"}},
                    answer : 'B'
                },
                {
                    question : "What event symbolizes the beginning of the French Revolution?",
                    choices : {{'A', "The tennis court oath"},
                               {'B', "The Women's March on Versailles"},
                               {'C', "The storming of the Bastille"},
                               {'D', "The execution of Louis XVI"}},
                    answer : 'C'
                },
                {
                    question : "Who was the king of France at the start of the Revolution?",
                    choices : {{'A', "Louis XIV"},
                               {'B', "Louis XV"},
                               {'C', "Louis XVI"},
                               {'D', "Napoleon Bonaparte"}},
                    answer : 'C'
                },
                {
                    question : "What document was adopted in 1789?",
                    choices : {{'A', "The Napoleonic Code"},
                               {'B', "The Declaration of the Rights of Man and of the Citizen"},
                               {'C', "The Magna Carta"},
                               {'D', "The French Constitution of 1791"}},
                    answer : 'B'
                },
                {
                    question : "Who was executed during the Reign of Terror?",
                    choices : {{'A', "Napoleon Bonaparte"},
                               {'B', "Maximilien Robespierre"},
                               {'C', "Marie Antoinette"},
                               {'D', "Voltaire"}},
                    answer : 'C'
                },
                {
                    question : "What was the main method of execution during the Revolution?",
                    choices : {{'A', "Firing squad"},
                               {'B', "Hanging"},
                               {'C', "Guillotine"},
                               {'D', "Burning at the stake"}},
                    answer : 'C'
                },
                {
                    question : "Who took power in France in 1799?",
                    choices : {{'A', "Robespierre"},
                               {'B', "Louis XVIII"},
                               {'C', "Napoleon Bonaparte"},
                               {'D', "Danton"}},
                    answer : 'C'
                },
                {
                    question : "Which political group led the Reign of Terror?",
                    choices : {{'A', "The Girondins"},
                               {'B', "The Jacobins"},
                               {'C', "The Royalists"},
                               {'D', "The Sans-Culottes"}},
                    answer : 'B'
                },
                {
                    question : "When was the French monarchy abolished?",
                    choices : {{'A', "1789"},
                               {'B', "1792"},
                               {'C', "1804"},
                               {'D', "1815"}},
                    answer : 'B'
                },
                {
                    question : "Which battle marked Napoleon's final defeat?",
                    choices : {{'A', "Austerlitz"},
                               {'B', "Waterloo"},
                               {'C', "Trafalgar"},
                               {'D', "Leipzig"}},
                    answer : 'B'
                }}
        },
        {
            name : "The Age of Exploration",
            questions : {
                {
                    question : "Who discovered America in 1492?",
                    choices : {{'A', "Vasco da Gama"},
                               {'B', "Ferdinand Magellan"},
                               {'C', "Christopher Columbus"},
                               {'D', "James Cook"}},
                    answer : 'C'
                },
                {
                    question : "Which explorer completed the first circumnavigation of the Earth?",
                    choices : {
                        {'A', "Christopher Columbus"},
                        {'B', "Marco Polo"},
                        {'C', "Ferdinand Magellan"},
                        {'D', "Amerigo Vespucci"}},
                    answer : 'C'
                },
                {
                    question : "Which country funded Columbus' voyages?",
                    choices : {
                        {'A', "Portugal"},
                        {'B', "England"},
                        {'C', "Spain"},
                        {'D', "France"}},
                    answer : 'C'
                },
                {
                    question : "What was the name of Columbus' flagship?",
                    choices : {
                        {'A', "Mayflower"},
                        {'B', "Santa Maria"},
                        {'C', "Endeavour"},
                        {'D', "Victory"}},
                    answer : 'B'
                },
                {
                    question : "Who discovered the sea route to India by sailing around Africa?",
                    choices : {
                        {'A', "Vasco da Gama"},
                        {'B', "Bartolomeu Dias"},
                        {'C', "Ferdinand Magellan"},
                        {'D', "Henry the Navigator"}},
                    answer : 'A'
                },
                {
                    question : "Which explorer is credited with naming the Pacific Ocean?",
                    choices : {
                        {'A', "Christopher Columbus"},
                        {'B', "Ferdinand Magellan"},
                        {'C', "Vasco Núñez de Balboa"},
                        {'D', "James Cook"}},
                    answer : 'B'
                },
                {
                    question : "Who was the first European to reach Australia?",
                    choices : {
                        {'A', "James Cook"},
                        {'B', "Abel Tasman"},
                        {'C', "Willem Janszoon"},
                        {'D', "William Dampier"}},
                    answer : 'C'
                },
                {
                    question : "Which explorer is known for his three voyages to the Pacific Ocean?",
                    choices : {
                        {'A', "James Cook"},
                        {'B', "Francis Drake"},
                        {'C', "Walter Raleigh"},
                        {'D', "John Cabot"}},
                    answer : 'A'
                },
                {
                    question : "Who was the first European to sail around the southern tip of Africa?",
                    choices : {
                        {'A', "Vasco da Gama"},
                        {'B', "Bartolomeu Dias"},
                        {'C', "Prince Henry the Navigator"},
                        {'D', "Pedro Álvares Cabral"}},
                    answer : 'B'
                },
                {
                    question : "Which explorer is credited with the European discovery of Brazil?",
                    choices : {
                        {'A', "Christopher Columbus"},
                        {'B', "Amerigo Vespucci"},
                        {'C', "Pedro Álvares Cabral"},
                        {'D', "Hernando de Soto"}},
                    answer : 'C'
                }}
        },
        {
            name : "Physical Geography: Seas and Oceans",
            questions : {
                {
                    question : "What is the largest ocean on Earth?",
                    choices : {
                        'A', "Atlantic Ocean",
                        'B', "Indian Ocean",
                        'C', "Arctic Ocean",
                        'D', "Pacific Ocean"},
                    answer : 'D'
                },
                {
                    question : "Which sea borders France to the southeast?",
                    choices : {
                        'A', "North Sea",
                        'B', "Baltic Sea",
                        'C', "Mediterranean Sea",
                        'D', "Black Sea"},
                    answer : 'C'
                },
                {
                    question : "What is the smallest ocean on Earth?",
                    choices : {
                        'A', "Arctic Ocean",
                        'B', "Southern Ocean",
                        'C', "Indian Ocean",
                        'D', "Atlantic Ocean"},
                    answer : 'A'
                },
                {
                    question : "Which sea is located between Europe and Africa?",
                    choices : {
                        'A', "Red Sea",
                        'B', "Black Sea",
                        'C', "Mediterranean Sea",
                        'D', "Caspian Sea"},
                    answer : 'C'
                },
                {
                    question : "What is the name of the sea between Australia and New Zealand?",
                    choices : {
                        'A', "Coral Sea",
                        'B', "Tasman Sea",
                        'C', "South China Sea",
                        'D', "Bering Sea"},
                    answer : 'B'
                },
                {
                    question : "Which ocean is home to the Mariana Trench, the deepest part of the world's oceans?",
                    choices : {
                        'A', "Atlantic Ocean",
                        'B', "Indian Ocean",
                        'C', "Pacific Ocean",
                        'D', "Southern Ocean"},
                    answer : 'C'
                },
                {
                    question : "What is the name of the sea between the United Kingdom and Norway?",
                    choices : {
                        'A', "Irish Sea",
                        'B', "North Sea",
                        'C', "Baltic Sea",
                        'D', "Celtic Sea"},
                    answer : 'B'
                },
                {
                    question : "Which sea is located between Saudi Arabia and Africa?",
                    choices : {
                        'A', "Arabian Sea",
                        'B', "Red Sea",
                        'C', "Persian Gulf",
                        'D', "Gulf of Oman"},
                    answer : 'B'
                },
                {
                    question : "What is the name of the sea located north of Russia?",
                    choices : {
                        'A', "Barents Sea",
                        'B', "Kara Sea",
                        'C', "Laptev Sea",
                        'D', "East Siberian Sea"},
                    answer : 'A'
                },
                {
                    question : "Which sea is located between Greece and Turkey?",
                    choices : {
                        'A', "Black Sea",
                        'B', "Adriatic Sea",
                        'C', "Ionian Sea",
                        'D', "Aegean Sea"},
                    answer : 'D'
                }}
        },
        {
            name : "Colonial Empires",
            questions : {
                {
                    question : "Which country had the largest colonial empire in the 19th century?",
                    choices : {
                        'A', "France",
                        'B', "Spain",
                        'C', "United Kingdom",
                        'D', "Portugal"},
                    answer : 'C'
                },
                {
                    question : "Which African country gained independence from France in 1962 after a war?",
                    choices : {
                        'A', "Morocco",
                        'B', "Algeria",
                        'C', "Tunisia",
                        'D', "Senegal"},
                    answer : 'B'
                },
                {
                    question : "Which European country colonized Brazil?",
                    choices : {
                        'A', "Spain",
                        'B', "France",
                        'C', "Netherlands",
                        'D', "Portugal"},
                    answer : 'D'
                },
                {
                    question : "Which country colonized India before its independence in 1947?",
                    choices : {
                        'A', "France",
                        'B', "Portugal",
                        'C', "United Kingdom",
                        'D', "Netherlands"},
                    answer : 'C'
                },
                {
                    question : "Which European country colonized Indonesia?",
                    choices : {
                        'A', "United Kingdom",
                        'B', "France",
                        'C', "Spain",
                        'D', "Netherlands"},
                    answer : 'D'
                },
                {
                    question : "Which African country was never colonized by European powers?",
                    choices : {
                        'A', "Ethiopia",
                        'B', "Kenya",
                        'C', "Nigeria",
                        'D', "South Africa"},
                    answer : 'A'
                },
                {
                    question : "Which country colonized the Philippines before the United States?",
                    choices : {
                        'A', "Portugal",
                        'B', "Netherlands",
                        'C', "United Kingdom",
                        'D', "Spain"},
                    answer : 'D'
                },
                {
                    question : "Which European country colonized large parts of North America in the 17th and 18th centuries?",
                    choices : {
                        'A', "Spain",
                        'B', "France",
                        'C', "Netherlands",
                        'D', "Sweden"},
                    answer : 'B'
                },
                {
                    question : "Which country colonized Australia and New Zealand?",
                    choices : {
                        'A', "France",
                        'B', "Netherlands",
                        'C', "United Kingdom",
                        'D', "Portugal"},
                    answer : 'C'
                },
                {
                    question : "Which European country had the first global empire in history?",
                    choices : {
                        'A', "Spain",
                        'B', "Portugal",
                        'C', "United Kingdom",
                        'D', "France"},
                    answer : 'B'
                }}
        },
        {
            name : "World Capitals",
            questions : {
                {
                    question : "What is the capital of Australia?",
                    choices : {
                        'A', "Sydney",
                        'B', "Canberra",
                        'C', "Melbourne",
                        'D', "Perth"},
                    answer : 'B'
                },
                {
                    question : "What is the capital of Canada?",
                    choices : {
                        'A', "Toronto",
                        'B', "Vancouver",
                        'C', "Ottawa",
                        'D', "Montreal"},
                    answer : 'C'
                },
                {
                    question : "What is the capital of Brazil?",
                    choices : {
                        'A', "São Paulo",
                        'B', "Rio de Janeiro",
                        'C', "Brasilia",
                        'D', "Salvador"},
                    answer : 'C'
                },
                {
                    question : "What is the capital of China?",
                    choices : {
                        'A', "Shanghai",
                        'B', "Beijing",
                        'C', "Hong Kong",
                        'D', "Shenzhen"},
                    answer : 'B'
                },
                {
                    question : "What is the capital of Japan?",
                    choices : {
                        'A', "Osaka",
                        'B', "Kyoto",
                        'C', "Tokyo",
                        'D', "Nagoya"},
                    answer : 'C'
                },
                {
                    question : "What is the capital of Russia?",
                    choices : {
                        'A', "St. Petersburg",
                        'B', "Moscow",
                        'C', "Kazan",
                        'D', "Novosibirsk"},
                    answer : 'B'
                },
                {
                    question : "What is the capital of South Africa?",
                    choices : {
                        'A', "Cape Town",
                        'B', "Johannesburg",
                        'C', "Pretoria",
                        'D', "Durban"},
                    answer : 'C'
                },
                {
                    question : "What is the capital of Argentina?",
                    choices : {
                        'A', "Buenos Aires",
                        'B', "Córdoba",
                        'C', "Rosario",
                        'D', "Mendoza"},
                    answer : 'A'
                },
                {
                    question : "What is the capital of Kazakhstan?",
                    choices : {
                        'A', "Almaty",
                        'B', "Astana",
                        'C', "Nursultan",
                        'D', "Shymkent"},
                    answer : 'C'
                },
                {
                    question : "What is the capital of Côte d'Ivoire?",
                    choices : {
                        'A', "Abidjan",
                        'B', "Bouaké",
                        'C', "Yamoussoukro",
                        'D', "Korhogo"},
                    answer : 'C'
                }}
        }}
};

int main()
{
    // Displaying the welcome message
    cout << "Welcome to our Geography and History quizz." << endl;
    cout << "Press enter to begin..." << endl;
    system("read");

    // Iniatilizing variables
    int score = 0;
    int minimum_score = 50 * 0.6; // 50 questions x 60% correct answer

    time_t begin;
    time(&begin);
    int question_number = 1;

    for (Subtopic topic : quizz_content.subtopics)
    {
        cout << endl;
        cout << topic.name << endl;
        cout << "-------------------------------" << endl;
        cout << endl;
        for (Question question : topic.questions)
        {
            char user_choice;
            cout << question.question << endl;
            for (Choice possibility : question.choices)
            {
                cout << possibility.letter << " : " << possibility.text << endl;
            }
            cout << "Votre choix : ";
            cin >> user_choice;
            if (toupper(user_choice) == question.answer)
            {
                score++;
                cout << "Good answer !" << endl;
            }
            else
            {
                cout << "Bad answer, it was anwser " << question.answer << "." << endl;
            }
            cout << "Score : " << score << "/" << question_number << endl;
            question_number++;
        }
    }
    time_t end;
    time(&end);

    if (score < minimum_score)
    {
        cout << "Test failed in " << (end - begin) << " seconds." << endl;
    }
    else
    {
        cout << "Test passed successfully ! (" << (end - begin) << "seconds)" << endl;
    }

    return 0;
}