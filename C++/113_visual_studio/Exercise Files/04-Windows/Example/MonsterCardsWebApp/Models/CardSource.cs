using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace MonsterCardsWebApp.Models
{
	public class CardSource
	{
		private List<MonsterCard> _cards;
		public CardSource()
		{
			_cards = new List<MonsterCard>();

			_cards.Add(new MonsterCard
			{
				Name = "Mingle",
				Slogan = "Double Trouble",
				EyeCount = 2,
				OriginalPrice = 5.99M,
				SellPrice = 15.95M,
				ImageUri = "Monster-Mingle-card.png",
				Description = "Mingle excels at doing twice the work in half the time, with pinpoint accuracy.  These skills serve her well in her role as Senior Data Analyst for an international cloud computing company. She's also got a penchant for ballroom dance, line dancing, and pretty much any kind of activity that lets her groove to music.",

			});
			_cards.Add(new MonsterCard
			{
				Name = "Yodel",
				Slogan = "Yodelay Hee Hoo!",
				EyeCount = 2,
				OriginalPrice = 5.99M,
				SellPrice = 6.95M,
				ImageUri = "Monster-Yodel-card.png",
				Description = "Yodel grew up in a family of singers and loud talkers and could never get a word in edgewise. Then his vast talent for yodeling emerged. Now he performs to adoring fans throughout the world, and always has the loudest voice at the dinner table. Incidentally, he's also a loud proponent of net neutrality, and spends countless hours moderating an internet forum devoted solely to that subject.",

			});
			_cards.Add(new MonsterCard
			{
				Name = "Squido",
				Slogan = "Yodelay Hee Hoo!",
				EyeCount = 2,
				OriginalPrice = 5.99M,
				SellPrice = 6.95M,
				ImageUri = "Monster-Squido-card.png",
				Description = "Squido's got his hands or rather tentacles, in everything. First and foremost, he's a web designer with an eye for visual aesthetics, but he's also rather keen on UX design and making sure what he creates translates optimally to the end user. In his off-hours he's an avid nature photographer and bowler.",

			});

			_cards.Add(new MonsterCard
			{
				Name = "Spook",
				Slogan = "Safe and Sound",
				EyeCount = 3,
				OriginalPrice = 5.99M,
				SellPrice = 23.95M,
				ImageUri = "Monster-Spook-card.png",
				Description = "Cracking code and battling hackers is Spook's forte. She holds a prominent position as Head of Cyber Security for the Department of Monster Defense, where she thwarts attacks on government computer systems as often as she blinks. When not at work, Spook delights in serving up a fright at haunted mansions and ghost walks.",

			});
			_cards.Add(new MonsterCard
			{
				Name = "Melville",
				Slogan = "Networking Guru",
				EyeCount = 2,
				OriginalPrice = 5.99M,
				SellPrice = 8.25M,
				ImageUri = "Monster-Melville-card.png",
				Description = "Setting up computer networks has always come easily to Melville. In his role as Senior Network Engineer for Landon Hotel, Melville builds complex blueprints for communication networks, a task that requires enormous attention to detail and patience. When not at work, Melville chooses less taxing mental activities, like hiking in the hills near his Silicon Valley home.",

			});
			_cards.Add(new MonsterCard
			{
				Name = "Filo",
				Slogan = "Baker by Day, Techie by Night",
				EyeCount = 3,
				OriginalPrice = 5.99M,
				SellPrice = 13.95M,
				ImageUri = "Monster-Filo-card.png",
				Description = "Filo was named after the wonderful, buttery pastry crust that monsters adore. She’s a prominent baker and pastry chef in monster circles and is always exploring and sharing new dessert trends. In her off time, however, she's quite the techie and dabbles in web and mobile app development. She even built a custom cake ordering app for her pastry business.",

			});
			_cards.Add(new MonsterCard
			{
				Name = "Blade",
				Slogan = "Monster APPetite",
				EyeCount = 1,
				OriginalPrice = 5.99M,
				SellPrice = 42.50M,
				ImageUri = "Monster-Blade-card.png",
				Description = "Blade freelances as a mobile app developer and has built some of the most popular Android and iOS apps used in modern monster society, including the award-winning Monster APPetite, which tracks calorie consumption and activity for the health-conscious monster. In his spare time, he competes in national agility contests with his border collie Winston."
			});
			_cards.Add(new MonsterCard
			{
				Name = "Timber",
				Slogan = "Database Expert",
				EyeCount = 2,
				OriginalPrice = 5.99M,
				SellPrice = 11.95M,
				ImageUri = "Monster-Timber-card.png",
				Description = "A natural-born problem-solver, Timber's especially excited to solve complex business problems using databases. As a database administrator for Globe Bank International, he's able to flex his mental muscles using his certifications in Oracle, Microsoft SQL Server, and MySQL. When not behind the computer, Timber can often be found biking, surfing, or lounging around with a good detective novel",

			});

			_cards.Add(new MonsterCard
			{
				Name = "Skedaddle",
				Slogan = "Game of Life",
				EyeCount = 1,
				OriginalPrice = 5.99M,
				SellPrice = 14.95M,
				ImageUri = "Monster-Skedaddle-card.png",
				Description = "When Skedaddle was a teenager, his parents couldn't keep him away from his Game Boy. In fact, they seriously worried that he might not find a suitable career.  Now as a prominent game developer for Red30 Tech, he's found his true calling…and put his family's worries to rest. You probably could have guessed this, but in his spare time Skedaddle loves to pay computer games.",

			});
			_cards.Add(new MonsterCard
			{
				Name = "Smiley",
				Slogan = "Don’t Worry, Be Happy!",
				EyeCount = 1,
				OriginalPrice = 5.99M,
				SellPrice = 32.95M,
				ImageUri = "Monster-Smiley-card.png",
				Description = "With the bad rap they get from movies, monsters have it pretty tough. Perhaps no monster has done more to squash stereotypes than Smiley, who can take anyone’s frown and turn it upside down. That's why Smiley has a reputation as the best computer support specialist on her IT team, three years running.",
				
			});
			_cards.Add(new MonsterCard
			{
				Name = "Frex",
				Slogan = "Born Leader",
				EyeCount = 4,
				OriginalPrice = 5.99M,
				SellPrice = 16.50M,
				ImageUri = "Monster-Frex-card.png",
				Description = "Frex has always had a knack for leadership, starting from his days of being a Monster Scout. After studying computer science in college, and working as an IT specialist at several large companies, he naturally followed the  management path.  Now, as an IT manager for a Fortune 500 company, he gets to put his technical know-how to work, while also leading a team of talented engineers. Frex's hobbies include golf, billiards, and community service.",

			});
			_cards.Add(new MonsterCard
			{
				Name = "Drift",
				Slogan = "In the Clouds",
				EyeCount = 2,
				OriginalPrice = 5.99M,
				SellPrice = 17.95M,
				ImageUri = "Monster-Drift-card.png",
				Description = "After years of everyone saying her head was in the clouds, Drift found her calling as a software engineer developing a well-known cloud solution for the computing giant, Red30 Tech. After work, she prefers to unwind by catching wind in her sail and paragliding high in the sky.",

			});
			
			foreach (var card in _cards)
			{
				card.ShortDescription = GetShortText(card.Description, 220) + "...";
			}


		}
		private string GetShortText(String candidate, int charCount)
		{
			if (candidate.Length > charCount)
			{
				return candidate.Substring(0, charCount);
			}
			else {
				return candidate;
			}
			
		
		}
		public List<MonsterCard> MonsterCards
		{
			get
			{
				return _cards;
			}
		}

	}
}
