use std::io;

fn main()
{
    let mut state = 0;

    let mut STR = 5;
    let mut PER = 5;  
    let mut END = 5;
    let mut CHA = 5;
    let mut INT = 5;
    let mut AGY = 5;
    let mut LUC = 5;

    let mut input = String::new();
    let mut strChange = String::new();
    let mut change : i32;
    let mut strSkill = String::new();
    let mut skill : i32;
    let mut points : i32;

    println!("Welcome to the Fallout character creator");
    loop 
    {
        println!("Current atributes:\n");

        println!("STR: {}", STR);
        println!("PER: {}", PER);
        println!("END: {}", END);
        println!("CHA: {}", CHA);
        println!("INT: {}", INT);
        println!("AGY: {}", AGY);
        println!("LUC: {}", LUC);

        println!("(1)Change (2)Continue:");

        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");

        if(input == "2")
        {
            break;
        }
        else if(input != "1")
        {
            println!("Invalid input. Please insert another entry!\n\n");
            continue;
        }
        io::stdin()
            .read_line(&mut strChange)
            .expect("Failed to read line");

        change = strChange.parse();

        if((change > 0 && change > points) || change < 0 || change > 10)
        {
            println!("Invalid option\n\n");
            continue;
        }

        println!("Which skill would you like to change?\n(1)STR (2)PER (3)END (4)CHA (5)INT (6)AGY (7) LUC");
        io::stdin()
            .read_line(&mut strSkill)
            .expect("Failed to read line");

        skill = strSkill.parse() - 1;

    }
    
}
