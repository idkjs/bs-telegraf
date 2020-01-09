/* js example from https://telegraf.js.org/#/?id=example */
const Telegraf = require('telegraf');
require('dotenv').config();

const bot = new Telegraf(process.env.TELEGRAM_TOKEN);
bot.start((ctx) => {
	console.log('context: ' + JSON.stringify(ctx.updateType, null, 2));
	ctx.reply('Welcome');
});
bot.help((ctx) => ctx.reply('Send me a sticker'));
bot.on('sticker', (ctx) => ctx.reply('👍'));
bot.hears('hi', (ctx) => ctx.reply('Hey there'));
bot.command('oldschool', (ctx) => ctx.reply('Hello'));
bot.command('modern', ({ reply }) => reply('Yo'));
bot.command('hipster', Telegraf.reply('λ'));
bot.launch();

// bot.use(async (ctx, next) => {
// 	const start = new Date();
// 	await next();
// 	const ms = new Date() - start;
// 	console.log('Response time: %sms', ms);
// });

// bot.on('text', (ctx) => {
// 	console.log('context' + JSON.stringify(ctx, null, 2));
// 	ctx.reply('Hello World');
// });
// bot.launch();
