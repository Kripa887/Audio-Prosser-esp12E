const volume = document.getElementById('volume');
const bass = document.getElementById('bass');
const mid = document.getElementById('mid');
const treble = document.getElementById('treble');
const balance = document.getElementById('balance');

volume.oninput = () =>
{
    document.getElementById('volumeValue').innerText = volume.value + ' dB';

    send();
}

bass.oninput = () =>
{
    document.getElementById('bassValue').innerText = bass.value + ' dB';

    send();
}

mid.oninput = () =>
{
    document.getElementById('midValue').innerText = mid.value + ' dB';

    send();
}

treble.oninput = () =>
{
    document.getElementById('trebleValue').innerText = treble.value + ' dB';

    send();
}

balance.oninput = () =>
{
    send();
}

function setInput(id)
{
    fetch('/input?id=' + id);
}

function send()
{
    fetch(`/set?volume=${volume.value}&bass=${bass.value}&mid=${mid.value}&treble=${treble.value}&balance=${balance.value}`);
}

async function updateVU()
{
    const response = await fetch('/vu');

    const value = await response.text();

    document.getElementById('bar').style.width = value + '%';
}

setInterval(updateVU,100);

if('serviceWorker' in navigator)
{
    navigator.serviceWorker.register('/sw.js');
}