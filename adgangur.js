var password = "12345";

function passcheck() {
    
if(document.getElementById('pass1').value != password) {
alert('Lykilorð rangt, reyndu aftur.');
return false;
}
if(document.getElementById('pass1').value == password) {
alert('Lykilorð rétt, veldu OK til að fara á síðu.');
}
}