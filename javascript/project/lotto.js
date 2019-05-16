"use strict";
var ary=[];

function randInt(min,max){ //random included min and max
    return Math.floor(Math.random()*(max-min+1))+min;
}

function findLotto(){
    ary=[];
    for(var i=0;i<7;i++){
        while(true){
            var val=randInt(1,45);
            if(ary.length==0 || ary.indexOf(val)==-1){
                ary.push(val);
                break;
            }
        }
    }
    
}

function printLotto(){
    findLotto();
    for(var i=0;i<7;i++){
        document.getElementById('l'+(i+1).toString()).innerHTML=ary[i];
    }
}

