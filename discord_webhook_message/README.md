Create discord webhook by going to Server Settings > Intergration > Webhooks > New Webhook/Edit existing one. 
Select the channels webhook is going to send text file. 
Remember the webhook URL.

For website.html:
- Download website.html
- Put your webhook URL at 2nd parameter of request.open(), change Username (webhook name) and "content" parameter at "params", then save.
- Run the website.html file, press the send button. The message should pop up in your discord setup channel.

For google_app.gs file:
- Create a new google sheet spreadsheet
- Go to Tool > Script editor
- Paste the code in
- Put your webhook URL at "discordUrl". Change "content" parameter at payload. Then save.
- Select dropdown button to select function to run. Then Press run button. The message should pup up in your discord setup channel

References:
https://dev.to/oskarcodes/send-automated-discord-messages-through-webhooks-using-javascript-1p01
https://stackoverflow.com/questions/59336498/send-a-message-to-discord-channels-via-google-apps-script
https://gist.github.com/Birdie0/78ee79402a4301b1faf412ab5f1cdcf9
