var isBulbOn=false;

function bulb_on_off() {
    var bulb = document.getElementsByClassName("bulb")[0],
        base = document.getElementsByClassName("base-yellow")[0],
        body = document.getElementsByTagName("body")[0],
        blush = document.getElementsByClassName("blush-container")[0],
        lip_happy = document.getElementsByClassName("lips-happy")[0],
        lip_sad = document.getElementsByClassName("lips-sad")[0];

    if(isBulbOn)
        off();
    else
        on();

    function on() {
        isBulbOn=true;
        // body.style.backgroundColor="#555555";
        bulb.style.backgroundColor="yellow";
        bulb.style.boxShadow="0 0 40px #ffd309";
        base.style.backgroundColor="yellow";
        blush.style.opacity="1";
        lip_sad.style.opacity="0";
        lip_happy.style.opacity="1";
    }

    function off() {
        isBulbOn=false;
        // body.style.backgroundColor="#000000";
        bulb.style.backgroundColor="#CCE8FF";
        bulb.style.boxShadow="none";
        base.style.backgroundColor="#CCE8FF";

    }

}

function sinluz(){
    isBulbOn=true;
    bulb_on_off();
}
function luz(){
    isBulbOn=false;
    bulb_on_off();
}