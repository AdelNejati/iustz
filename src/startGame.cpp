#include "../headers/startGame.h"

void IUSTZ()
{
    clean();
    this_thread::sleep_for(std::chrono::milliseconds(1000));
    int time = 400;
    for (int i = 0; i < 20; ++i)
    {
        time -= 20;
        cout << " #########      ##       ##        #######        ##########\n";
        cout << "    ##          ##       ##       #                   ##    \n";
        cout << "    ##          ##       ##      ##                   ##    \n";
        cout << "    ##          ##       ##       #                   ##    \n";
        cout << "    ##          ##       ##        #######            ##    \n";
        cout << "    ##          ##       ##               #           ##    \n";
        cout << "    ##          ##       ##               ##          ##    \n";
        cout << "    ##           #       #                #           ##    \n";
        cout << " ########         #######         ########            ##    \n";
        this_thread::sleep_for(std::chrono::milliseconds(10));
        clean();
        this_thread::sleep_for(std::chrono::milliseconds(time));
    }
    cout << " #########      ##       ##        #######        ##########\n";
    cout << "    ##          ##       ##       #                   ##    \n";
    cout << "    ##          ##       ##      ##                   ##    \n";
    cout << "    ##          ##       ##       #                   ##    \n";
    cout << "    ##          ##       ##        #######            ##    \n";
    cout << "    ##          ##       ##               #           ##    \n";
    cout << "    ##          ##       ##               ##          ##    \n";
    cout << "    ##           #       #                #           ##    \n";
    cout << " ########         #######         ########            ##    \n";
    this_thread::sleep_for(std::chrono::milliseconds(1000));
    clean();

    cout << " #########      ##       ##        #######        ##########";
    print("      ########## \n", color_dark_red);
    cout << "    ##          ##       ##       #                   ##    ";
    print("             ##  \n", color_dark_red);
    cout << "    ##          ##       ##      ##                   ##    ";
    print("            ##   \n", color_dark_red);
    cout << "    ##          ##       ##       #                   ##    ";
    print("           ##    \n", color_dark_red);
    cout << "    ##          ##       ##        #######            ##    ";
    print("          ##     \n", color_dark_red);
    cout << "    ##          ##       ##               #           ##    ";
    print("         ##      \n", color_dark_red);
    cout << "    ##          ##       ##               ##          ##    ";
    print("        ##       \n", color_dark_red);
    cout << "    ##           #       #                #           ##    ";
    print("       ##        \n", color_dark_red);
    cout << " ########         #######         ########            ##    ";
    print("      ########## \n", color_dark_red);
    this_thread::sleep_for(std::chrono::milliseconds(2000));

    output("\n\nIn the final days, a mysterious virus swept across the world,\n", color_light_blue, 1);
    output("turning all humans into mindless Enemys. The once bustling cities were now eerily quiet,\n", color_light_blue, 1);
    output("with only the sound of groaning and shuffling echoing through the empty streets.\n", color_light_blue, 1);
    output("As the days turned into weeks those who survive decided to make a last stand against the Enemy.\n", color_light_blue, 1);
    output("They want you as a brave champion to go to war with Enemys and save humanity.\n", color_light_blue, 1);
    output("In this way, there are factions of animals that have survived in these conditions,\n", color_light_blue, 1);
    output("and some humans have been forced to coexist with these animals.\n", color_light_blue, 1);
    output("You can join them and use their help. But don't forget that no one can be trusted...\n\n", color_light_blue, 1);
    output("No one can be trusted...\n\n\n", color_light_blue, 1);

    output("Press any key to continue\n", color_orange, 25);
    char q = '1';
    q = getch();
}
void createNewPlayer(int i)
{
    clean();
    Player *player = new Player;
    string name;
    string job;
    string gender;
    string age = "age";
    string faction;

    output("Player " + to_string(i + 1) + ": \n\n", color_pink, color_black);
    output("Enter your name: \n", color_pink, color_black);
    cin >> name;

    output("\nEnter your job: \n", color_pink, color_black);
    cin >> job;

    output("\nEnter your gender: \n", color_pink, color_black);
    cin >> gender;

    while (inputNumber(age) == -1)
    {
        output("\nEnter your age: \n", color_pink, color_black);
        cin >> age;
    }
    while (inputNumber(faction) != 1 && inputNumber(faction) != 2 && inputNumber(faction) != 3 && inputNumber(faction) != 4)
    {
        output("\nYou can choose one of these factions :\n", color_pink, color_black);
        output("\n 1. THE ENDLESS SERPENT\n", color_pink, color_black);
        output("\n 2. CULT OF THE RAT\n", color_pink, color_black);
        output("\n 3. THE PALE RAVEN\n", color_pink, color_black);
        output("\n 4. THE SUPPLICANT SPIDER\n", color_pink, color_black);
        cin >> faction;
    }

    player->setName(name);
    player->setJob(job);
    player->setGender(gender);
    player->setAge(inputNumber(age));

    if (inputNumber(faction) == 1)
    {
        player->takeDamage(15);
        player->reduceStamina(15);
        player->setMoney(100);
        Wood *item = new Wood;
        ZombiePoison *zombiePoison = new ZombiePoison;
        player->AddItemToBackPack(zombiePoison);
        DeadlyPoison *deadlyPoison = new DeadlyPoison;
        player->AddItemToBackPack(deadlyPoison);
        SleepingPoison *sleepingPoison = new SleepingPoison;
        player->AddItemToBackPack(sleepingPoison);
        player->setItemInHand(item);
    }
    if (inputNumber(faction) == 2)
    {
        player->takeDamage(30);
        player->reduceStamina(0);
        player->setMoney(800);
        for (int i = 0; i < 2; i++)
        {
            Meat *meat = new Meat;
            player->AddItemToBackPack(meat);
        }
        Wood *item = new Wood;
        player->setItemInHand(item);
    }
    if (inputNumber(faction) == 3)
    {
        player->takeDamage(0);
        player->reduceStamina(30);
        player->setMoney(200);
        for (int i = 0; i < 2; i++)
        {
            Grenade *grenade = new Grenade;
            player->AddItemToBackPack(grenade);
        }
        Knife *knife = new Knife;
        player->setItemInHand(knife);
    }
    if (inputNumber(faction) == 4)
    {
        player->takeDamage(0);
        player->reduceStamina(0);
        player->setMoney(400);
        player->upRawSkillPoint();
        player->upRawSkillPoint();
        player->upRawSkillPoint();
        Wood *item = new Wood;
        player->setItemInHand(item);
    }

    Players.push_back(player);
}
void startGame()
{
    string num = "num";
    IUSTZ();
    clean();
    while (inputNumber(num) == -1)
    {
        cout << "enter number of players : ";
        cin >> num;
    }

    for (int i = 0; i < inputNumber(num); i++)
    {
        createNewPlayer(i);
    }

    Player *player = Players[0];
    gameLoop(player, inputNumber(num));
}