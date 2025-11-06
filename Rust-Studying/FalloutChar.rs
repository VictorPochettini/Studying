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
    let mut skill = String::new();

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
            println!("Invalid input. Please insert another entry!");
            continue;
        }
        io::stdin()
            .read_line(&mut strChange)
            .expect("Failed to read line");

        change = strChange.parse();
    }
    
}
