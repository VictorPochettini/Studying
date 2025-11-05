use std::io;

fn main()
{
    let mut estado= 0;

    let mut STR = 5;
    let mut PER = 5;  
    let mut END = 5;
    let mut CHA = 5;
    let mut INT = 5;
    let mut AGY = 5;
    let mut LUC = 5;
    
    let mut skills = [&STR, &PER, &END, &CHA, &INT, &AGY, &LUC];

    let mut input = String::new();
    let mut strChange = String::new();
    let mut change : i32;

    println!("Welcome to the Fallout character creator");
    loop 
    {
        println!("Aqui estão seus atributos atuais:\n");

        println!("STR: {}", STR);
        println!("PER: {}", PER);
        println!("END: {}", END);
        println!("CHA: {}", CHA);
        println!("INT: {}", INT);
        println!("AGY: {}", AGY);
        println!("LUC: {}", LUC);

        println!("Deseja (1)Alterar (2)Continuar:");

        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");

        if(input == "2")
        {
            break;
        }
        else if(input != "1")
        {
            println!("Entrada inválida. Insira outro valor");
            continue;
        }
        io::stdin()
            .read_line(&mut strChange)
            .expect("Failed to read line");

        change = strChange.parse();
    }
    
}
