#define NUMBER_OF_ADMIN_QUESTIONS 3

#define NUMBER_OF_DEFINED_QUESTIONS 20

#define NUMBER_OF_MONEY_ROUND_QUESTIONS 10  //NOTE: IT HAS TO BE LESS OR EQUAL TO NUMBER_OF_DEFINED_QUESTIONS

#define QUESTION_MONEY 3500

struct qualification_round_questions
{
    char *question;
    char *answers[4];
    int correctAnswer;
    int correctAnswerIndex;
};
struct qualification_round_questions qq[NUMBER_OF_ADMIN_QUESTIONS];

struct money_round_questions
{
    char *question;
    char *answers[4];
    int correctAnswer;
    bool used;
    int correctAnswerIndex;
};
struct money_round_questions mq[NUMBER_OF_DEFINED_QUESTIONS] =
{
    {
/*0*/   "Which city is the capital of Australia?", {"Sydney", "Canberra", "Melbourne", "Brisbane"}, 2
    },
    {
/*1*/   "Which Apollo 11 astronaut did not set foot on the moon?", {"Neil A. Armstrong", "Michael Collins", "Edwin E. \"Buzz\" Aldrin, Jr.", "Jim Lovell"}, 2
    },
    {
/*2*/   "The rule of thumb or principle telling us that the simplest explanation is more likely the correct one is known as Occam's what?", {"Sword", "Arrow", "Razor", "Shaver"}, 3
    },
    {
/*3*/   "The ghost town Pripyat is found in which country?", {"Ukraine", "Belarus", "Russia", "Kazakhstan"}, 1
    },
    {
/*4*/   "When did D-Day (Normandy landings (codenamed Operation Neptune)) happen?", {"6 May 1944", "6 July 1944", "6 June 1945", "6 June 1944"}, 4
    },
    {
/*5*/   "Which male actor has the most number of Academy Awards (\"Oscars\") in the leading actor category?", {"Jack Nicholson", "Marlon Brando", "Daniel Day-Lewis", "Tom Hanks"}, 3
    },
    {
/*6*/   "The Statue of Liberty was a gift to the United States from which country?", {"Spain", "Portugal", "Canada", "France"}, 4
    },
    {
/*7*/   "Jimmy Page, John Bonham, Robert Plant, John Paul Jones were members of which music band?", {"The Doors", "Queen", "Led Zeppelin", "Deep Purple"}, 3
    },
    {
/*8*/   "Who wrote Carrie, Salem's Lot, The Shining, The Stand?", {"Stephen King", "Bram Stoker", "Kurt Vonnegut", "John Steinbeck"}, 1
    },
    {
/*9*/   "On the human body, a keloid is a type of what?", {"Scars", "Freckles", "Nipples", "Nails"}, 1
    },
    {
/*10*/  "James Naismith invented which sport?", {"Baseball", "Basketball", "Hockey", "Rugby"}, 2
    },
    {
/*11*/  "Who is ranked 2nd in NBA all-time points list?", {"Kobe Bryant", "Kareem Abdul-Jabbar", "Wilt Chamberlain", "Karl Malone"}, 4
    },
    {
/*12*/  "In J.R.R. Tolkien's The Hobbit, how many Dwarves were on the quest with Bilbo?", {"10", "12", "13", "15"}, 3
    },
    {
/*13*/  "Which planet in the solar system is the hotest?", {"Mercury", "Venus", "Jupiter", "Neptune"}, 2
    },
    {
/*14*/  "Who killed US President Abraham Lincoln? ", {"John Wilkes Booth", "Lee Harvey Oswald", "John Hinckley", "Michael Schiavo"}, 1
    },
    {
/*15*/  "What is the color of the bull of an archery target? ", {"Blue", "Red", "White", "Gold"}, 4
    },
    {
/*16*/  "What is the height of the Burj Khalifa Tower in Dubai?", {"634 m", "628.8 m", "829.8 m", "885.4 m"}, 3
    },
    {
/*17*/  "Ordinary table salt is sodium chloride. What is baking soda?", {"Sodium bicarbonate", "Potassium hydroxide", "Potassium carbonate", "Potassium chloride"}, 1
    },
    {
/*18*/  "Benedict Cumberbatch appears as the eponymous hero, created by Steve Ditko, in what 2016 superhero film?", {"Daredevil", "Doctor Strange", "Doctor Octopus", "Blade"}, 2
    },
    {
/*19*/  "Which reggae singing star died 11th May 1981? ", {"Peter Tosh", "Damian Marley", "Bob Marley", "Desmond Dekker"}, 3
    }
};

