<?php
$array = array("paper" , "rock" ,"scissors" );
$flipped = array(
    "scissors" => 1,
    "rock"     => 2,
    "paper"    => 3
);

$name = (string)readline("Choose rock, paper, or scissors: ");
$i = rand(0,2);
$computer = $array[$i];
if ($flipped[$name] > $flipped[$computer])
    echo "Congratulations! You won! The computer chose " . $computer . ".";
elseif ($flipped[$name] < $flipped[$computer])
    echo "Sorry, you lost. The computer chose " . $computer . ".";
else
    echo "Equal! The computer chose " . $computer . ".";
?>