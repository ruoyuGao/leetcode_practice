## Welcome!

This package will help you manage Pipelines and your AWS Infrastructure with the power of CDK!

You can view this package's pipeline, [PSASManifoldLambda](https://pipelines.amazon.com/pipelines/PSASManifoldLambda)

## Development




```bash
brazil ws create --name PSASManifoldLambda
cd PSASManifoldLambda
brazil ws use \
  --versionset PSASManifoldLambda/development \
  --platform AL2_x86_64 \
  --package PSASManifoldLambdaCDK
cd src/PSASManifoldLambdaCDK
brazil-build
```

## Useful links:
* https://builderhub.corp.amazon.com/docs/native-aws/developer-guide/cdk-pipeline.html
* https://code.amazon.com/packages/BONESConstructs/blobs/HEAD/--/packages/@amzn/pipelines/README.md
* https://code.amazon.com/packages/CDKBuild/blobs/HEAD/--/README.md
* https://docs.aws.amazon.com/cdk/api/latest/versions.html


## Deploy to personal stack
1. Run mwinit -o

1. Export your AWS Account ID
  e.g, Add `export DEVELOPER_ACCOUNT_ID="933730433805";` to your ~/.zshrc
       Run `source ~/.zshrc`

1. Build package
  `bbr`

1. Bootstrap your account - This sets up required Cloudformation resources for CDK to deploy to your account.
  `bb deploy:bootstrap BONESBootstrap-3332167-<YOUR_ACCOUNT_ID>-us-east-1`
  You can find the correct one in `build/cdk.out/`

1. Setup a your own config in all the config files in the folder `src/PSASManifoldLambda/configuration/brazil-config`
  ```
  # add your own config like this form in all files with this content
  #    <YOUR_ACCOUNT_ID>: <YOUR_USER_NAME>@amazon.com
  dev.<YOUR_ALIAS>.consumer-endpoint.AWSSOCSysEng = {
     endpoint-arn = "arn:aws:kinesis:us-east-1:<YOUR_ACCOUNT_ID>:stream/AWSSOCSysEngIntegTestConsumerStream";
     role-arn = "arn:aws:iam::<YOUR_ACCOUNT_ID>:role/CanaryConsumerStreamWriterRole";
  };
  ```
  if you don't have the folder `src/PSASManifoldLambda`, please run `brazil ws use --package PSASManifoldLambda` to check it.
  
1. Deploy assets (Make sure to build the Lambda package first)
  `bb deploy:assets PSASManifold-Lambda-dev-<YOUR_ALIAS>` # Deploy Lambda payload
  It's OK if you see:
  ```
    Nothing to refresh for stack PSASManifold-Infra-dev-<YOUR_ALIAS>
    Failed to get resources for stack 'PSASManifold-Lambda-dev-<YOUR_ALIAS>' (stack name: PSASManifold-Lambda-dev-<YOUR_ALIAS>) Error [ValidationError]: Stack with id PSASManifold-Lambda-dev-iad does not exist
    ...
    BUILD SUCCEEDED
  ```
  It just means your stack has not been created yet.

1. Deploy lambda stacks

   `bb cdk deploy PSASManifold-Lambda-dev-<YOUR_ALIAS>`
  
1. Deploy hydra stacks

   `bbr && bb deploy:assets PSASManifold-Hydra-dev-<YOUR_ALIAS> && bb cdk deploy PSASManifold-Hydra-dev-<YOUR_ALIAS>`

1. OR deploy the monitor stack that depends on other stacks, which automatically deploys dependency stacks.

   `bbr && bb deploy:assets PSASManifold-Monitoring-dev-<YOUR_ALIAS> && bb cdk deploy PSASManifold-Monitoring-dev-<YOUR_ALIAS>`

1. OR excuslively deploy a single stack

   `bb cdk deploy --exclusively PSASManifold-Monitoring-dev-<YOUR_ALIAS>`

## Synthesize Regional Dashboard Wikis
1. Make sure the path you're synthesizing to has "Amazon Employee" as primary owner in its permissions settings, otherwise the synthesis fails with permission denied. For example, https://w.amazon.com/bin/view/PSAS/AmazonOptics/Manifold/Monitoring needs to have "Amazon Employee" as primary owner so that all its children pages can be synthesized. This is due to the limitation from Wiki where it currently does not support Sigv4 client from editing private pages:
  * https://issues.amazon.com/issues/KTC-4644
  * https://w.amazon.com/bin/view/AmazonWiki/API/Client/#HWhatarethelimitationsofusingSigV4toauthenticatemyAPIrequest3F

1. Synthesize Wiki by running:
  `bb app deployWiki`

## Synthesize Daily Dashboard Wikis
1. Make sure the path you are synthesizing is writable by "Amazon Employees". Refer to previous section for more details.
1. Synthesize Dev Wiki by running:
  `bb app deployDevDailyDashboard`
1. Once CDK changes are merged, synthesize the real Wiki dashboard
  `bb app deployDailyDashboard`
