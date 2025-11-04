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
    }
    
}