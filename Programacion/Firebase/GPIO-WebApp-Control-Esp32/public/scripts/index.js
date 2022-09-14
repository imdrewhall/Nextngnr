const loginElement = document.querySelector('#login-form');
const contentElement = document.querySelector("#content-sign-in");
const userDetailsElement = document.querySelector('#user-details');
const authBarElement = document.querySelector("#authentication-bar");

// Elements for GPIO states
const stateElement1 = document.getElementById("state1");
const stateElement2 = document.getElementById("state2");
const stateElement3 = document.getElementById("state3");
const stateElement4 = document.getElementById("state4");
const stateElement5 = document.getElementById("state5");
const stateElement6 = document.getElementById("state6");

const stateprueba = document.getElementById("lala");

// Button Elements
const btn1On = document.getElementById('btn1On');
const btn1Off = document.getElementById('btn1Off');
const btn2On = document.getElementById('btn2On');
const btn2Off = document.getElementById('btn2Off');
const btn3On = document.getElementById('btn3On');
const btn3Off = document.getElementById('btn3Off');
const btn4On = document.getElementById('btn4On');
const btn4Off = document.getElementById('btn4Off');
const btn5On = document.getElementById('btn5On');
const btn5Off = document.getElementById('btn5Off');
const btn6On = document.getElementById('btn6On');
const btn6Off = document.getElementById('btn6Off');



var dbPathOutput0 = 'board1/outputs/string/language';

// Database path for GPIO states
var dbPathOutput1 = 'board1/outputs/digital/12';
var dbPathOutput2 = 'board1/outputs/digital/13';
var dbPathOutput3 = 'board1/outputs/digital/14';
var dbPathOutput4 = 'board1/outputs/digital/25';
var dbPathOutput5 = 'board1/outputs/digital/32';
var dbPathOutput6 = 'board1/outputs/digital/34';


// Database references
var dbRefOutput0 = firebase.database().ref().child(dbPathOutput0);
var dbRefOutput1 = firebase.database().ref().child(dbPathOutput1);
var dbRefOutput2 = firebase.database().ref().child(dbPathOutput2);
var dbRefOutput3 = firebase.database().ref().child(dbPathOutput3);
var dbRefOutput4 = firebase.database().ref().child(dbPathOutput4);
var dbRefOutput5 = firebase.database().ref().child(dbPathOutput5);
var dbRefOutput6 = firebase.database().ref().child(dbPathOutput6);


// MANAGE LOGIN/LOGOUT UI
const setupUI = (user) => {
  if (user) {
    //toggle UI elements
    loginElement.style.display = 'none';
    contentElement.style.display = 'block';
    authBarElement.style.display ='block';
    userDetailsElement.style.display ='block';
    userDetailsElement.innerHTML = user.email;





    //Update states depending on the database value
    dbRefOutput1.on('value', snap => {
        if(snap.val()==1) {
            stateElement1.innerText="ON";
        }
        else{
            stateElement1.innerText="OFF";
        }
    });
    dbRefOutput2.on('value', snap => {
        if(snap.val()==1) {
            stateElement2.innerText="ON";
        }
        else{
            stateElement2.innerText="OFF";
        }
    });
    dbRefOutput3.on('value', snap => {
        if(snap.val()==1) {
            stateElement3.innerText="ON";
        }
        else{
            stateElement3.innerText="OFF";
        }
    });

    dbRefOutput4.on('value', snap => {
        if(snap.val()==1) {
            stateElement4.innerText="ON";
        }
        else{
            stateElement4.innerText="OFF";
        }
    });

    dbRefOutput5.on('value', snap => {
        if(snap.val()==1) {
            stateElement5.innerText="ON";
        }
        else{
            stateElement5.innerText="OFF";
        }
    });

    dbRefOutput6.on('value', snap => {
        if(snap.val()==1) {
            stateElement6.innerText="ON";
        }
        else{
            stateElement6.innerText="OFF";
        }
    });

    stateprueba.onsubmit = () =>{
        dbRefOutput0.set(stateprueba.value);
    }
    
    // Update database uppon button click
    btn1On.onclick = () =>{
        dbRefOutput1.set(1);
    }
    btn1Off.onclick = () =>{
        dbRefOutput1.set(0);
    }

    btn2On.onclick = () =>{
        dbRefOutput2.set(1);
    }
    btn2Off.onclick = () =>{
        dbRefOutput2.set(0);
    }

    btn3On.onclick = () =>{
        dbRefOutput3.set(1);
    }
    btn3Off.onclick = () =>{
        dbRefOutput3.set(0);
    }

    btn4On.onclick = () =>{
        dbRefOutput4.set(1);
    }
    btn4Off.onclick = () =>{
        dbRefOutput4.set(0);
    }

    btn5On.onclick = () =>{
        dbRefOutput5.set(1);
    }
    btn5Off.onclick = () =>{
        dbRefOutput5.set(0);
    }

    btn6On.onclick = () =>{
        dbRefOutput6.set(1);
    }
    btn6Off.onclick = () =>{
        dbRefOutput6.set(0);
    }

    
  // if user is logged out
  } else{
    // toggle UI elements
    loginElement.style.display = 'block';
    authBarElement.style.display ='none';
    userDetailsElement.style.display ='none';
    contentElement.style.display = 'none';
  }
}